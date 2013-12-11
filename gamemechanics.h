
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QWidget>
#include <QImage>
#include <QPoint>

class GameMechanics : public QWidget
{
    Q_OBJECT

private:
    int pieceCount;
    QImage** array;
    QPoint emptyPeace;
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем
public:
    QString* imageName;
    GameMechanics(QWidget *parent = 0);
    ~GameMechanics();
signals:

public slots:
    void newGame(QString* imageName);
    void hint();
    void mixArray();
    void qclick();
    void imagePressed(QImage &pict1, QImage &pict2);

};

#endif // GAMEMECHANICS_H
