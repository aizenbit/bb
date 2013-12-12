/*
 *  Главное окно программы
 */
#ifndef UI_H
#define UI_H

#include <QtGui>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

#include "gamemechanics.h"
#include "newgamewidget.h"

class UI : public QMainWindow
{
    Q_OBJECT

private:
     QMenu* gameMenu; //меню "Игра"
     QMenu* aboutMenu; //меню "Справка" или что-то в этом роде
     QMenuBar* menuBar; //панель меню
     QLabel* creatorsLabel; //окошко "О создателях"
     QLabel* aboutTheGameLabel;//окошко "Об игре"
     NewGameWidget* newGameWidget;//окошко "Новая игра"
     GameMechanics* gameMechanics;//основная механика игры.

     friend class NewGameWidget;
private slots:
     void newGame();
     void aboutTheGame();
     void creators();
     void showImage();

public:
    UI(QWidget *parent = 0);
    ~UI();
};

#endif // UI_H

//тестовая строчка
