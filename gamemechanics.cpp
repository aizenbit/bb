#include "gamemechanics.h"
#include <QPainter>
#include <QtCore/qmath.h>
#include <QLabel>
#include <QMouseEvent>

GameMechanics::GameMechanics(QWidget *parent) :
        QWidget(parent)
{
    imageName = new QString();
        pieceCount = 3;
    array = new qwaqwa*[pieceCount];
        for (int i = 0; i < pieceCount; i++)
        array[i] = new qwaqwa[pieceCount];

    for (int x = 0; x<pieceCount;x++)
        for(int y = 0; y<pieceCount;y++)
        {
            array[x][y].x=x;
            array[x][y].y=y;
        }
    emptyImagePos.setX(pieceCount-1);
    emptyImagePos.setY(pieceCount-1);
    typeOfPainting = empty;
}

//-----------------------------------------

void GameMechanics::mixArray()
    //Начинаем перемешивать части картинок по алгоритму
{
         for(int x = 0; x < ((pieceCount*pieceCount-1)*(rand()%(9)));x++)
             array[x/pieceCount][x%pieceCount].img.swap(array[(x+1)/pieceCount][(x+1)%pieceCount].img);
         for(int y = 0; y < ((pieceCount*pieceCount-1)*(rand()%(7)));y++)//
             array[y/pieceCount][y%pieceCount].img.swap(array[(y+1)/pieceCount][(y+1)%pieceCount].img);
}

//-----------------------------------------


void GameMechanics::newGame()
{
    pieceWidth = this->width() / pieceCount;
    pieceHeight = this->height() / pieceCount;
    typeOfPainting = fullImage;
    QImage temp(*imageName);
    temp = temp.scaled(QSize(this->width(),this->height()));
    image = &temp;
    for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                array[x][y].img = image->copy(pieceWidth*x,pieceHeight*y,pieceWidth,pieceHeight);
    emptyImagePos.setX(pieceCount-1);
    emptyImagePos.setY(pieceCount-1);
   // mixArray();
}

//----------------------------------------

void GameMechanics::hint()
{
    typeOfPainting = fullImage;
    repaint();}

//----------------------------------------

GameMechanics::~GameMechanics()
{
    //delete imageName; TODO: хз почему, но тут прога выбрасывает исключение
    //delete image;
        for (int i = 0; i < pieceCount; i++)
                delete[] array[i];
        delete[] array;
}

//----------------------------------------

void GameMechanics::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.begin(this);
    switch(typeOfPainting)
    {
    case pieces:
        pieceWidth = this->width()/pieceCount;
        pieceHeight = this->height()/pieceCount;
        //рисуем картинки
        for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                //if( !( (array[x][y].x == emptyImagePos.x()) && (array[x][y].y == emptyImagePos.y()) ) )
                    painter.drawImage(pieceWidth*x,pieceHeight*y,array[x][y].img);
        //рисуем линии между картинками
        painter.setPen(QColor(0,0,0));
        for(int x = pieceWidth; x < this->width();x+=pieceWidth)
            painter.drawLine(x,0,x,this->height());
        for(int y = pieceHeight; y < this->height();y+=pieceHeight)
            painter.drawLine(0,y,this->width(),y);
        break;

    case fullImage:
        for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                painter.drawImage(pieceWidth*array[x][y].x,pieceHeight*array[x][y].y,array[x][y].img);
        break;

    default:
        painter.drawText(this->width()/2-70,this->height()/2-15,"Please, begin the game");
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
//Подаем элементы массива того
//И все равно, мне кажется это странным
{
    if(!array[0][0].img.isNull() && typeOfPainting == pieces)
    {
        int x = (int)pos.x(); //% pieceWidth;
        int y = (int)pos.y(); //% pieceHeight;
        x /= pieceWidth;
        y /= pieceHeight;
        //Условие монструозно, но штоподелать, если нет исключающего "или"?
        if( ((abs(x - emptyImagePos.x()) == 1) || (abs(y - emptyImagePos.y()) == 1)) && !((abs(x - emptyImagePos.x()) == 1) && (abs(y - emptyImagePos.y()) == 1)) )
        {
            qwaqwa tempPiece = array[x][y];
            array[x][y]= array[emptyImagePos.x()][emptyImagePos.y()];
            array[emptyImagePos.x()][emptyImagePos.y()] = tempPiece;
            emptyImagePos.setX(x);
            emptyImagePos.setY(y);
            repaint();
        }
    }
    if(typeOfPainting == fullImage)
    {
        typeOfPainting = pieces;
        repaint();
    }
}

//----------------------------------------
