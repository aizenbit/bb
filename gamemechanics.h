
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QWidget>
#include <QImage>
#include <QPoint>

class GameMechanics : public QWidget
{
    Q_OBJECT

private:
    struct qwaqwa
    {
        int x,y;
        QImage img;
    };
    int pieceCount;
    QImage* image;
    qwaqwa** array;
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем
public:
    QString* imageName;
    GameMechanics(QWidget *parent = 0);
    ~GameMechanics();
signals:

public slots:
    void newGame();
    void hint();
    void mixArray();
    //void qclick();
    void imagePressed(qwaqwa *pict1, qwaqwa *pict2);

};

#endif // GAMEMECHANICS_H
