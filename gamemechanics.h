
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
        int x, y;
        QImage img;
    };
    int pieceCount;
    bool winflag;
    QImage *image;
    qwaqwa **array;
    QPoint emptyImagePos;
    int pieceWidth;
    int pieceHeight;
    TypeOfPainting typeOfPainting;
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем
    void mousePressEvent(QMouseEvent *);
    void resizeArray();
    //virtual void mousePressEvent(QMouseEvent *event);
public:
    QString *imageName;
    void deleteImageName();
    GameMechanics(QWidget *parent = 0);
    ~GameMechanics();
signals:
    void win();
public slots:
    void newGame();
    void hint();
    void mixArray();
    int swapEmpty(int, int);
    bool checkArray();
    void imagePressed(QPointF);
    void changeLevel(int);
};

#endif // GAMEMECHANICS_H
