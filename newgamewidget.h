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
#include "gamemechanics.h"

class NewGameWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* pathLayout;
    QHBoxLayout* buttonsLayout;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QPushButton* browseButton;
    QLineEdit* pathLineEdit;
    QString* imageName;
    QRadioButton* defaultImageRB;
    QRadioButton* userImageRB;
    GameMechanics* gameMechanics;
    QSlider* slider;

public:
    NewGameWidget(GameMechanics* gmMechanics, QWidget *parent = 0);
    ~NewGameWidget();

signals:

public slots:
    void newGame();
    void browse();
};

#endif // NEWGAMEWIDGET_H
