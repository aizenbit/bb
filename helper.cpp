#include "helper.h"
#include <QPainter>

Helper::Helper(QWidget *parent) :
    QWidget(parent)
{
    repaint();
}

void Helper::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.begin(this);
    painter.drawText(12,12,"Это то место, где будет картинка");
    painter.end();
}
