#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QObject>

class GameMechanics : public QObject
{
    Q_OBJECT

public:
    GameMechanics(QObject *parent = 0);

signals:

public slots:
    void newGame();
    void hint();
};

#endif // GAMEMECHANICS_H
