/*
 *  Класс, отвечающий за игровую механику
 */
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include <QWidget>

class GameMechanics : public QWidget
{
    Q_OBJECT

    friend class Helper;

private:
    int pieceCount;
    QImage** array;
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем
public:
    QString* imageName;
    GameMechanics(QWidget *parent = 0);
    ~GameMechanics();
signals:

public slots:
    void newGame(QString* imageName);
    void hint();
};

#endif // GAMEMECHANICS_H
