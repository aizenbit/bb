/*
 *  Класс, отвечающий за игровую механику
 */
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QObject>

class GameMechanics : public QObject
{
    Q_OBJECT


public:
    QString* imageName;
    GameMechanics(QObject *parent = 0);
    ~GameMechanics();
signals:

public slots:
    void newGame(QString* imageName);
    void hint();
};

#endif // GAMEMECHANICS_H
