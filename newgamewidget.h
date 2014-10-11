#ifndef NEWGAMEWIDGET_H
#define NEWGAMEWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QRadioButton>
#include <QSlider>
#include <QLabel>

#include "gamemechanics.h"

class NewGameWidget : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLayout;//планировка виджетов
    QHBoxLayout *pathLayout, *buttonsLayout, *RBLayout;
    QPushButton *okButton; //кнопки
    QPushButton *cancelButton;
    QPushButton *browseButton;
    QLineEdit *pathLineEdit; //строка с путём к файлу
    QRadioButton *defaultImageRB; //переключатель
    QRadioButton *userImageRB;
    GameMechanics *gameMechanics; //игровая механика
    QSpinBox *spinBox;
    QLabel *spinBoxLabel;

private slots:
    void newGame();
    void browse();

signals:
    void wrongImage();

public:
    NewGameWidget(GameMechanics *, QWidget *parent = 0);
    ~NewGameWidget();
};

#endif // NEWGAMEWIDGET_H
