/*
 *  Окошко "Новая игра"
 */

#ifndef NEWGAMEWIDGET_H
#define NEWGAMEWIDGET_H

// Для Qt4:

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


// Для Qt5:
/*
#include <QtGui/QtGui>
#include <QtWidgets>
*/
#include "gamemechanics.h"

class NewGameWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *mainLayout;//планировка виджетов
    QHBoxLayout *pathLayout;
    QHBoxLayout *buttonsLayout;
    QPushButton *okButton; //кнопки
    QPushButton *cancelButton;
    QPushButton *browseButton;
    QLineEdit *pathLineEdit; //строка с путём к файлу
    QRadioButton *defaultImageRB; //переключатель
    QRadioButton *userImageRB;
    GameMechanics *gameMechanics; //игровая механика
    QSlider *slider; //ползунок выбора сложности
    QLabel *sliderLabel; //надпись над ползунком
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
