#include "gamemechanics.h"
#include <QPainter>
#include <QtCore/qmath.h>

GameMechanics::GameMechanics(QWidget *parent) :
	QWidget(parent)
{
	imageName = new QString("");
	pieceCount = 3;
	array = new QImage*[pieceCount];
	for (int i = 0; i < pieceCount; i++)
		array[i] = new QImage[pieceCount];
	emptyPeace = QPoint(pieceCount-1,pieceCount-1);
}

//-----------------------------------------

int random(int min,int max)
{
	return (rand()%(max-min+1)+min);
}
void GameMechanics::mixArray()
{
	//Начинаем перемешивать части картинок по алгоритму
	int x1,x2,y1,y2;
	for(int x=0;x<pieceCount;x++){
		for(int y=0;y<pieceCount;y++){
			if(array[x][y]==array[0][0]){
				x2=x;
				y2=y;
			}
		}
	}
	for(int k=0;k<pieceCount*pieceCount*5;k++){
		if(k%2){

			x1=x2;
			if(y2>pieceCount/2){
				y1 = random(0,y2-1);
			}
			else{
				y1 = random(y2+1,pieceCount-1);
			}

			if(y1>y2){
				for(int x=y2;x<y1;x++){
					array[x1][x]=array[x1][x+1];
				}
				array[x1][y1]= array[0][0];
			}
			else{
				for(int x=y2;x>y1;x--){
					array[x1][x]=array[x1][x-1];
				}
				array[x1][y1]=array[0][0];
			}
			y2=y1;
		}
		else{
			if(x2>pieceCount/2){
				x1= random(0,x2-1);
			}
			else{
				x1 = random(x2+1,pieceCount-1);
			}
			y1=y2;
			if(x1>x2){
				for(int x=x2;x<x1;x++){
					array[x][y1]=array[x+1][y1];
				}
				array[x1][y1]=array[0][0];
			}
			else{
				for(int x=x2;x>x1;x--){
					array[x][y1]=array[x-1][y1];
				}
				array[x1][y1]=array[0][0];
			}
			x2=x1;
		}
	}//for k= 0,n*n
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

void GameMechanics::newGame(QString* imageName)
{

}

//-----------------------------------------

void GameMechanics::hint()
{

}

//-----------------------------------------

GameMechanics::~GameMechanics()
{
	delete imageName;
	for (int i = 0; i < pieceCount; i++)
		delete[] array[i];
	delete[] array;
}

//-----------------------------------------

void GameMechanics::paintEvent(QPaintEvent *paintEvent)
{
	QPainter painter(this);
	painter.begin(this);
	for(int x = 0;x < pieceCount;x++)
		for(int y = 0;y<pieceCount;y++)
			painter.drawImage(this->width()/pieceCount*x,this->height()/pieceCount*y,array[x][y]);
	painter.end();
}

//-----------------------------------------
