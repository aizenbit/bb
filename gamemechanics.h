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
    struct Piece
    {
        int x, y;
        QImage img;
    };
    int pieceCount;//количество картинок
    bool winflag;//выиграл или ещё нет
    QImage *image;//исходное изображение
    Piece **array;//массив кусочков изображения
    QPoint emptyImagePos;//позиция пустого кусочка
    int pieceWidth;//длина кусочка
    int pieceHeight;//высота кусочка
    TypeOfPainting typeOfPainting;//что именно рисовать
    void paintEvent(QPaintEvent *); //тут мы рисуем
    void mousePressEvent(QMouseEvent *); //обработка нажатий мыши
    void mixArray(); //перемешивание кусочков
    bool swapEmpty(int, int); //перемещение кусочка с картинкой на пустое место
    bool checkArray(); //проверка на выигрыш

public:
    QString *imageName; //путь к картинке
    GameMechanics(QWidget *parent = 0);
    ~GameMechanics();

signals:
    void win(); //сигнал выигрыша

public slots:
    void newGame(); //начало новой игры
    void showImage(); //вывод полной картинки на экран
    void changeLevel(int); //изменение уровня сложности
};

#endif // GAMEMECHANICS_H
