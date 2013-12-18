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
    pieceWidth = this->width()/pieceCount;
    pieceHeight = this->height()/pieceCount;
    typeOfPainting = pieces;
    QImage temp(*imageName);
    temp = temp.scaled(QSize(this->width(),this->height()));
    image = &temp;
    for(int x = 0;x < pieceCount;x++)
    {
        for(int y = 0;y<pieceCount-1;y++)
        {
            array[x][y].img = image->copy(pieceWidth*x,pieceHeight*y,pieceWidth,pieceHeight);
        }
    }
    for(int x = 0;x<pieceCount-1;x++)
    {
        array[x][pieceCount-1].img = image->copy(pieceWidth*x,pieceHeight*(pieceCount-1),pieceWidth,pieceHeight);
    }
    array[pieceCount-1][pieceCount-1].img = QImage();
    emptyImagePos.setX(pieceCount-1);
    emptyImagePos.setY(pieceCount-1);
   // mixArray();
}

//----------------------------------------

void GameMechanics::hint()
{
    QLabel *lbl = new QLabel("Меня нажали!");
    lbl->show();
    QPainter painter(this);
    painter.begin(this);

    {
        pieceWidth = this->width()/pieceCount;
        pieceHeight = this->height()/pieceCount;
        //рисуем картинки
        for(int x = 0; x < pieceCount; x++)
        {
        for(int y = 0; y < pieceCount-1; y++)
        {
        if ( array[x][y].x != pieceCount-1 && array[x][y].y != pieceCount - 1)
        painter.drawImage(pieceWidth*array[x][y].x,pieceHeight*array[x][y].y,array[x][y].img);
        }
        }
    };
    painter.end();
}

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
        {
            for(int y = 0; y < pieceCount; y++)
            {
                painter.drawImage(pieceWidth*x,pieceHeight*y,array[x][y].img);
            }
        }
        //рисуем линии между картинками
        painter.setPen(QColor(0,0,0));
        for(int x = pieceWidth; x < this->width();x+=pieceWidth)
            painter.drawLine(x,0,x,this->height());
        for(int y = pieceHeight; y < this->height();y+=pieceHeight)
            painter.drawLine(0,y,this->width(),y);
        break;
    case fullImage:

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
    imagePressed(event->posF());
}

//----------------------------------------

void GameMechanics::imagePressed(QPointF pos)
//Подаем элементы массива того
//И все равно, мне кажется это странным
{
    int x = (int)pos.x(); //% pieceWidth;
    int y = (int)pos.y(); //% pieceHeight;
    x /= pieceWidth;
    y /= pieceHeight;
    //Условие монструозно, но штоподелать, если нет исключающего "или"?
    if( ((abs(x - emptyImagePos.x()) == 1) || (abs(y - emptyImagePos.y()) == 1)) && !((abs(x - emptyImagePos.x()) == 1) && (abs(y - emptyImagePos.y()) == 1)) )
    {
        array[x][y].img.swap(array[emptyImagePos.x()][emptyImagePos.y()].img);
        emptyImagePos.setX(x);
        emptyImagePos.setY(y);
        repaint();
    }
    if(!array[0][0].img.isNull())
    {
        int x = (int)pos.x(); //% pieceWidth;
        int y = (int)pos.y(); //% pieceHeight;
        x /= pieceWidth;
        y /= pieceHeight;
        //Условие монструозно, но штоподелать, если нет исключающего "или"?
        if( ((abs(x - emptyImagePos.x()) == 1) || (abs(y - emptyImagePos.y()) == 1)) && !((abs(x - emptyImagePos.x()) == 1) && (abs(y - emptyImagePos.y()) == 1)) )
        {
            array[x][y].img.swap(array[emptyImagePos.x()][emptyImagePos.y()].img);
            emptyImagePos.setX(x);
            emptyImagePos.setY(y);
            repaint();
        }
    }
}

//----------------------------------------
