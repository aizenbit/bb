#include "gamemechanics.h"
#include <QtCore/qmath.h>

GameMechanics::GameMechanics(QObject *parent) :
    QObject(parent)
{
    imageName = new QString("");
    pieceCount = 3;
    array = new QImage*[pieceCount];
    for (int i = 0; i < pieceCount; i++)
        array[i] = new QImage[pieceCount];
    emptyPeace = QPoint(pieceCount-1,pieceCount-1);
}
//-----------------------------------------
void GameMechanics::mixArray()
{
    //Начинаем перемешивать части картинок по алгоритму
    for ( int k = 0; k <= int(qPow(pieceCount,4.0)); k++)
    {
        for ( int y = 0; y < pieceCount; y++)
        {
            for ( int x = 0; x < pieceCount; x++)
            {
                if (rand() % 100 > 50)
                {
                    if (array[y][x].location.x = array[pieceCount-1][pieceCount-1].location.y
                        && array[y][x].location.x = array[pieceCount-1][pieceCount-1].location.x - array[y][x].width
                        || array[y][x].location.x = array[pieceCount-1][pieceCount-1].location.x + array[pieceCount-1][pieceCount-1].width)
                    {
                        imagePressed(array[y][x]);
                    }
                    else
                    {
                        if (array[y][x].location.x = array[pieceCount-1][pieceCount-1].location.x
                            && array[y][x].location.y = array[pieceCount-1][pieceCount-1].location.y - array[y][x].height
                            || array[y][x].location.y = array[pieceCount-1][pieceCount-1].location.y + array[pieceCount-1][pieceCount -1].height)
                        {
                            imagePressed(array[y][x]); //Получаем конечное расположение картинок
                        }
                    }
                }
            }
        }
    }
}

//-----------------------------------------

void GameMechanics::imagePressed()
{

}

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
