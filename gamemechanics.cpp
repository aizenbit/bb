#include "gamemechanics.h"
#include <QPainter>
GameMechanics::GameMechanics(QWidget *parent) :
    QWidget(parent)
{
    imageName = new QString("");
    pieceCount = 3;
    array = new QImage*[pieceCount];
    for (int i = 0; i < pieceCount; i++)
        array[i] = new QImage[pieceCount];
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
