#ifndef UI_H
#define UI_H

#include <QtGui>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include "helper.h"
#include "gamemechanics.h"

/*
 *  Главное окно программы
 */

class UI : public QMainWindow
{
    Q_OBJECT

private:
     QMenu* gameMenu; //меню "Игра"
     QMenu* aboutMenu; //меню "Справка" или что-то в этом роде
     QMenuBar* menuBar; //панель меню
     QLabel* creatorsLabel; //окошко "О создателях"
     QLabel* aboutTheGameLabel;//окошко "Об игре"

private slots:
     void newGame();
     void aboutTheGame();
     void creators();
     void showImage();
public:
    UI(QWidget *parent = 0);
    ~UI();
    Helper* helper; //"холст"

    GameMechanics* gameMechanics;//основная механика игры. Пусть пока будет тут

};

#endif // UI_H
