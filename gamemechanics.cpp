#include "gamemechanics.h"

GameMechanics::GameMechanics(QObject *parent) :
    QObject(parent)
{
    imageName = new QString("");
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
}

//-----------------------------------------
