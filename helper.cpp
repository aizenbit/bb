#include "helper.h"
#include <QPainter>

Helper::Helper(QWidget *parent) :
    QWidget(parent)
{
}

//-----------------------------------------

void Helper::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.begin(this);
    painter.drawText(12,12,"��� �� �����, ��� ����� ��������");
    painter.end();
}

//-----------------------------------------
