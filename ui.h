#ifndef UI_H
#define UI_H

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
     NewGameWidget *newGameWidget;//окошко "Новая игра"
     GameMechanics *gameMechanics;//основная механика игры.
     QLabel *youWinLable; //табличка "Вы выиграли"
     friend class NewGameWidget;

public:
    UI(QWidget *parent = 0);
    ~UI();

public slots:
    void showAboutBox();
    void showCreatorsBox();
    void showErrorBox();
};

#endif // UI_H
