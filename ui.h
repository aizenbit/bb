/*
 *  Главное окно
 */

#ifndef UI_H
#define UI_H

// Для Qt4:
/*
 *#include <QtGui>
 *#include <QLabel>
 *#include <QMainWindow>
 *#include <QMenu>
 *#include <QMenuBar>
*/

// Для Qt5:
#include <QtGui/QtGui>
#include <QtWidgets>

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
     friend class NewGameWidget;

public:
    UI(QWidget *parent = 0);
    ~UI();

public slots:
    void showAboutBox();
};

#endif // UI_H
