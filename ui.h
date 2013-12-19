/*
 *  Главное окно
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
     QMenu *gameMenu; //меню "Игра"
     QMenu *aboutMenu; //меню "Справка"
     QMenuBar *menuBar; //панель меню
     QLabel *creatorsLabel; //окошко "Об авторах"
     QLabel *aboutTheGameLabel;//окошко "Об игре"
     NewGameWidget *newGameWidget;//окошко "Новая игра"
     GameMechanics *gameMechanics;//основная механика игры.
     QLabel *youWinLable; //табличка "Вы выиграли"
     friend class NewGameWidget; //делаем окошко "Новая игра" дружественным

private slots:
     void newGame(); //начало новой игры
     void aboutTheGame(); //вывод окна "об игре"
     void creators(); //вывод окна "Об авторах"

public:
    UI(QWidget *parent = 0);
    ~UI();
};

#endif // UI_H
