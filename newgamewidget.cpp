#include "newgamewidget.h"

NewGameWidget::NewGameWidget(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QVBoxLayout();
    buttonsLayout = new QHBoxLayout();
    okButton = new QPushButton(tr("&Ok"));
    cancelButton = new QPushButton(tr("&Cancel"));
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonsLayout);

}
