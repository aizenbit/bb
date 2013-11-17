#ifndef NEWGAMEWIDGET_H
#define NEWGAMEWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class NewGameWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonsLayout;
    QPushButton* okButton;
    QPushButton* cancelButton;
public:
    explicit NewGameWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // NEWGAMEWIDGET_H
