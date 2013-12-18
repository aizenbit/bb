
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
    QPoint emptyImagePos;
    int pieceWidth;
    int pieceHeight;
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем
    void mousePressEvent(QMouseEvent *);
    //virtual void mousePressEvent(QMouseEvent *event);
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
    void imagePressed(QPointF);

};

#endif // GAMEMECHANICS_H
