/*
 *  Помогает рисовать.
 *  Точнее - является тем местом, где мы рисуем, "холстом"
 */
#ifndef HELPER_H
#define HELPER_H

#include <QWidget>

class Helper : public QWidget
{
    Q_OBJECT

private:
    virtual void paintEvent(QPaintEvent *); //тут мы рисуем

public:
    explicit Helper(QWidget *parent = 0);

signals:

public slots:

};

#endif // HELPER_H
