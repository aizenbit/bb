
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QObject>
#include <QImage>
#include <QPoint>

class GameMechanics : public QObject
{
    Q_OBJECT

private:
    int pieceCount;
    QImage** array;
    QPoint emptyPeace;
public:
    QString* imageName;
    GameMechanics(QObject *parent = 0);
    ~GameMechanics();
signals:

public slots:
    void newGame(QString* imageName);
    void hint();
    void mixArray();
    void imagePressed();

};

#endif // GAMEMECHANICS_H
