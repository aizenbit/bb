#ifndef UI_H
#define UI_H

#include <QtGui>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include "helper.h"

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
public:
    UI(QWidget *parent = 0);
    ~UI();
    Helper* helper; //"холст" Пока не уверен, каким он будет, так что пусть будет public

};

#endif // UI_H
