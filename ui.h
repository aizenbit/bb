#ifndef UI_H
#define UI_H

#include <QMainWindow>

class UI : public QMainWindow
{
    Q_OBJECT

public:
    UI(QWidget *parent = 0);
    ~UI();
};

#endif // UI_H
