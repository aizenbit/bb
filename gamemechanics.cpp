#include "gamemechanics.h"
#include <QPainter>
#include <QtCore/qmath.h>
#include <QLabel>

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
}

//-----------------------------------------

void GameMechanics::mixArray()
{ 	//Начинаем перемешивать части картинок по алгоритму
    int x1,y1,x2,y2;
    x1=0;
    y1=0;
    for(int x=0;x<pieceCount;x++){
        for(int y=0;y<(pieceCount+1);y++)
            if(y==pieceCount)
            {
                qwaqwa t;
                t = array[x][y];
                array[x][y] = array[x+1][y];
                array[x+1][y] = t;
            }
            else
            {
                qwaqwa t;
                t = array[x][y];
                array[x][y] = array[x][y+1];
                array[x][y+1] = t;
            }
    }
    for(int k=0;k<(pieceCount*(rand()%(5)));k++){
       for(y2=0;y2<pieceCount;y2++)
           for(x2=0;x2<(pieceCount+1);x2++){
            if(x2==pieceCount)
            {
                qwaqwa t;
                t = array[x2][y2];
                array[x2][y2] = array[x2][y2+1];
                array[x2][y2+1] = t;
            }
            else
            {
                qwaqwa t;
                t = array[x2][y2];
                array[x2][y2] = array[x2+1][y2];
                array[x2+1][y2] = t;
            }
        }
    }
}


//-----------------------------------------


void GameMechanics::newGame()
{
    int pieceWidth = this->width()/pieceCount;
    int pieceHeight = this->height()/pieceCount;
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
}

//----------------------------------------

void GameMechanics::hint()
{

}

//----------------------------------------

GameMechanics::~GameMechanics()
{
    //delete imageName; //TODO: хз почему, но на этом моменте прога выбрасывает исключение.
    //delete image;
	for (int i = 0; i < pieceCount; i++)
		delete[] array[i];
	delete[] array;
}



void GameMechanics::paintEvent(QPaintEvent *paintEvent)
{
	QPainter painter(this);
	painter.begin(this);

    int pieceWidth = this->width()/pieceCount;
    int pieceHeight = this->height()/pieceCount;
    //рисуем картинки
    for(int x = 0; x < pieceCount; x++)
    {
        for(int y = 0; y < pieceCount-1; y++)
        {
            painter.drawImage(pieceWidth*x,pieceHeight*y,array[x][y].img);
        }
    }
    for(int x = 0; x < pieceCount-1; x++)
    {
        painter.drawImage(pieceWidth*x,pieceHeight*(pieceCount-1),array[x][pieceCount-1].img);
    }
    //рисуем линии между картинками
    painter.setPen(QColor(0,0,0));
    for(int x = pieceWidth; x < this->width();x+=pieceWidth)
        painter.drawLine(x,0,x,this->height());
    for(int y = pieceHeight; y < this->height();y+=pieceHeight)
        painter.drawLine(0,y,this->width(),y);

    painter.end();
}

void GameMechanics::imagePressed(qwaqwa *pict1, qwaqwa *pict2)
//Подаем элементы массива того
//И все равно, мне кажется это странным
{
        qwaqwa *temp;
        temp=pict1;
        pict1=pict2;
        pict2=temp;
}

//----------------------------------------
