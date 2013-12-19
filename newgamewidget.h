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
    QVBoxLayout *mainLayout;
    QHBoxLayout *pathLayout;
    QHBoxLayout *buttonsLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *browseButton;
    QLineEdit *pathLineEdit;
    QRadioButton *defaultImageRB;
    QRadioButton *userImageRB;
    GameMechanics *gameMechanics;
    QSlider *slider;
    QLabel *sliderLabel;
public:
    NewGameWidget(GameMechanics *, QWidget *parent = 0);
    ~NewGameWidget();

signals:

public slots:
    void newGame();
    void browse();
};

#endif // NEWGAMEWIDGET_H
