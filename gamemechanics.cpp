#include "gamemechanics.h"
#include <QPainter>
#include <QtCore/qmath.h>
#include <QLabel>
#include <QMouseEvent>
#include <QtDebug>

GameMechanics::GameMechanics(QWidget *parent) :
        QWidget(parent)
{
    imageName = new QString();
    pieceCount = 3;
    array = new Piece*[pieceCount];
    for (int i = 0; i < pieceCount; i++)
        array[i] = new Piece[pieceCount];

    for (int x = 0; x < pieceCount; x++)
        for(int y = 0; y < pieceCount; y++)
        {
            array[x][y].x = x;
            array[x][y].y = y;
        }
    typeOfPainting = empty;
    winflag = false;
}

//-----------------------------------------

void GameMechanics::mixArray()
    //Начинаем перемешивать части картинок по алгоритму
{
    int mas[2] = {-1,1};
    int x, y;
    for(int i = 0; i<23 * pieceCount; i++)
    {
        x = abs((mas[rand() % 2] + emptyImagePos.x()) % pieceCount);
        y = abs((mas[rand() % 2] + emptyImagePos.x()) % pieceCount);
        if (!swapEmpty(x, emptyImagePos.y()))
            i--;
        if (!swapEmpty(emptyImagePos.x(), y))
            i--;
    }
}

//-----------------------------------------

void GameMechanics::newGame()
{
    pieceWidth = this->width() / pieceCount;
    pieceHeight = this->height() / pieceCount;
    typeOfPainting = fullImage;
    QImage temp(*imageName);
    temp = temp.scaled(QSize(this->width() + pieceCount, this->height()));
    image = &temp;
    for (int x = 0; x < pieceCount; x++)
        for(int y = 0; y < pieceCount; y++)
        {
            array[x][y].x = x;
            array[x][y].y = y;
        }
    for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                array[x][y].img = image->copy(pieceWidth * x, pieceHeight * y, pieceWidth, pieceHeight);
    emptyImagePos.setX(pieceCount - 1);
    emptyImagePos.setY(pieceCount - 1);
    winflag = false;
    repaint();
    mixArray();
    qDebug() << "\n\n\n---------------------\n\n\n" << *imageName;
    typeOfPainting = fullImage;
}

//----------------------------------------

void GameMechanics::hint()
{
    typeOfPainting = fullImage;
    repaint();
}

//----------------------------------------

GameMechanics::~GameMechanics()
{
        for (int i = 0; i < pieceCount; i++)
                delete[] array[i];
        delete[] array;
}

//----------------------------------------

void GameMechanics::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.begin(this);
    int n = 0;
    switch(typeOfPainting)
    {
    case pieces:
        pieceWidth = this->width() / pieceCount;
        pieceHeight = this->height() / pieceCount;
        //рисуем картинки
        for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                    painter.drawImage(pieceWidth * x,pieceHeight * y + y, array[x][y].img);
        painter.setPen(QColor(0, 0, 0));
        painter.setBrush(QColor(255, 255, 255));
        painter.drawRect(pieceWidth * emptyImagePos.x(), pieceHeight * emptyImagePos.y() + emptyImagePos.y(), pieceWidth, pieceHeight);
        //рисуем линии между картинками

        for(int x = pieceWidth; x < this->width(); x += pieceWidth)
            painter.drawLine(x, 0, x, this->height());
        for(int y = pieceHeight; y < this->height(); y += pieceHeight, n++)
            painter.drawLine(0, y + n, this->width(), y+n);
        break;

    case fullImage:
        for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                painter.drawImage(pieceWidth * array[x][y].x, pieceHeight * array[x][y].y, array[x][y].img);
        break;

    default:
        painter.drawText(this->width() / 2 - 70, this->height() / 2 - 15, "Begin the game, please!");
        break;
    };
    painter.end();
}

//----------------------------------------

void GameMechanics::mousePressEvent(QMouseEvent *event)
{
    imagePressed(event->localPos());
}

//----------------------------------------

void GameMechanics::imagePressed(QPointF pos)
{
    if(typeOfPainting == pieces)
    {
        int x = (int)pos.x();
        int y = (int)pos.y();
        x /= pieceWidth;
        y /= pieceHeight;
        if ( x == emptyImagePos.x() && y == emptyImagePos.y())
            return;
        swapEmpty(x,y);
        repaint();
        if(!winflag && checkArray())
        {
            win();
            typeOfPainting = fullImage;
        }

    }
    if(typeOfPainting == fullImage && !winflag)
    {
        typeOfPainting = pieces;
        repaint();
    }
    if(typeOfPainting == fullImage && winflag)
    {
        repaint();
    }
}

//----------------------------------------

int GameMechanics::swapEmpty(int x, int y)
{
    if( (abs(x - emptyImagePos.x()) == 1 && y == emptyImagePos.y()) || (abs(y - emptyImagePos.y()) == 1 && x == emptyImagePos.x()) )
    {
        Piece tempPiece = array[x][y];
        array[x][y] = array[emptyImagePos.x()][emptyImagePos.y()];
        array[emptyImagePos.x()][emptyImagePos.y()] = tempPiece;
        emptyImagePos.setX(x);
        emptyImagePos.setY(y);
        return 1;
    }
    else return 0;
}

//----------------------------------------

bool GameMechanics::checkArray()
{
    for(int x = 0; x < pieceCount; x++)
        for(int y = 0; y < pieceCount; y++)
            if(array[x][y].x != x || array[x][y].y != y) return 0;
    winflag = true;
    return 1;
}

//----------------------------------------

void GameMechanics::changeLevel(int level)
{
    if (level > 1 && level <6)
    {
        for (int i = 0; i < pieceCount; i++)
                delete[] array[i];
        delete[] array;
        pieceCount = level;
        array = new Piece*[pieceCount];
            for (int i = 0; i < pieceCount; i++)
            array[i] = new Piece[pieceCount];

        for (int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
            {
                array[x][y].x = x;
                array[x][y].y = y;
            }
    }
}

//----------------------------------------
void GameMechanics::deleteImageName()
{
    delete imageName;
}
