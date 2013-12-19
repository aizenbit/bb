
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QWidget>
#include <QImage>
#include <QPoint>

class GameMechanics : public QWidget
{
    Q_OBJECT
enum TypeOfPainting {fullImage, pieces, empty};
private:
    struct qwaqwa
    {
        int x,y;
        QImage img;
    };
    int pieceCount;
    bool winflag;
    QImage* image;
    qwaqwa** array;
    QPoint emptyImagePos;
    int pieceWidth;
    int pieceHeight;
    TypeOfPainting typeOfPainting;
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем
    void mousePressEvent(QMouseEvent *);
    void resizeArray();
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
    int swapEmpty(int x, int y);
    int checkArray();
    //void qclick();
    void imagePressed(QPointF);

};

#endif // GAMEMECHANICS_H
