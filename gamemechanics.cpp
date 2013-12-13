#include "gamemechanics.h"
#include <QPainter>
#include <QtCore/qmath.h>
#include <QLabel>

GameMechanics::GameMechanics(QWidget *parent) :
	QWidget(parent)
{
    imageName = new QString();
	pieceCount = 3;
	array = new QImage*[pieceCount];
	for (int i = 0; i < pieceCount; i++)
		array[i] = new QImage[pieceCount];
	emptyPeace = QPoint(pieceCount-1,pieceCount-1);

}

//-----------------------------------------


void GameMechanics::mixArray()
{ 	//Начинаем перемешивать части картинок по алгоритму
    int x1,y1,x2,y2;
    x1=0;
    y1=0;
	for(int x=0;x<pieceCount;x++){
        for(int y=0;y<(pieceCount+1);y++){
            if(y==pieceCount)
                {
                imagePressed(array[x][y], array[x+1][y]);
                }
                else
                   {
                     imagePressed(array[x][y], array[x][y+1]);
                    }
		}
	}
    for(int k=0;k<(pieceCount*(rand()%(5)));k++){
       for(y2=0;y2<pieceCount;y2++){
         for(x2=0;x2<(pieceCount+1);x2++){
            if(x2==pieceCount)
                {
                imagePressed(array[x2][y2], array[x2][y2+1]);
                }
                else
                   {
                     imagePressed(array[x2][y2], array[x2+1][y2]);
                    }
        }
    }
    }
}
//-----------------------------------------

void GameMechanics::imagePressed(QImage &pict1, QImage &pict2)
{
	QImage temp;
	temp=pict1;
	pict1=pict2;
	pict2=temp;

}

//-----------------------------------------

void GameMechanics::newGame()
{
    int width = this->width();
    QImage temp(*imageName);
    temp = temp.scaled(QSize(this->width(),this->height()));
    image = &temp;
    for(int x = 0;x < pieceCount;x++)
        for(int y = 0;y<pieceCount;y++)
            array[x][y] = image->copy(this->width()/pieceCount*x,this->height()/pieceCount*y,this->width()/pieceCount,this->height()/pieceCount);          
}

//-----------------------------------------

void GameMechanics::hint()
{

}

//-----------------------------------------

GameMechanics::~GameMechanics()
{
    //delete imageName; //TODO: хз почему, но на этом моменте прога выбрасывает исключение.
    //delete image;
	for (int i = 0; i < pieceCount; i++)
		delete[] array[i];
	delete[] array;
}

//-----------------------------------------

void GameMechanics::paintEvent(QPaintEvent *paintEvent)
{
	QPainter painter(this);
	painter.begin(this);

    int pieceWidth = this->width()/pieceCount;
    int pieceHeight = this->height()/pieceCount;
    //рисуем картинки
    for(int x = 0; x < pieceCount; x++)
        for(int y = 0; y < pieceCount; y++)
            painter.drawImage(pieceWidth*x,pieceHeight*y,array[x][y]);
    //рисуем линии между картинками
    painter.setPen(QColor(0,0,0));
    for(int x = pieceWidth; x < this->width();x+=pieceWidth)
        painter.drawLine(x,0,x,this->height());
    for(int y = pieceHeight; y < this->height();y+=pieceHeight)
        painter.drawLine(0,y,this->width(),y);
	painter.end();
}

//-----------------------------------------
