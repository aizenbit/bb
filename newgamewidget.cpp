#include "newgamewidget.h"

NewGameWidget::NewGameWidget(QString* imgName, QWidget *parent) :
    QWidget(parent)
{
    imageName = imgName;

    //------------------Buttons------------------
    okButton = new QPushButton(tr("&Ok"));
    cancelButton = new QPushButton(tr("&Cancel"));
    browseButton = new QPushButton(tr("&Browse"));

    //------------------RadioButtons-------------
    defaultImageRB = new QRadioButton(tr("Default Image"));
    userImageRB = new QRadioButton(tr("User Image"));
    userImageRB->setChecked(true);

    pathLineEdit = new QLineEdit();

    //------------------connections---------------
    connect(okButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(newGame()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(browseButton,SIGNAL(clicked()),this,SLOT(browse()));
    connect(defaultImageRB, SIGNAL(clicked(bool)), browseButton, SLOT(setDisabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)), browseButton, SLOT(setEnabled(bool)));
    connect(defaultImageRB, SIGNAL(clicked(bool)), pathLineEdit, SLOT(setDisabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)), pathLineEdit, SLOT(setEnabled(bool)));

    //------------------Layouts------------------
    mainLayout = new QVBoxLayout();
    buttonsLayout = new QHBoxLayout();
    pathLayout = new QHBoxLayout();
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    pathLayout->addWidget(pathLineEdit);
    pathLayout->addWidget(browseButton);
    mainLayout->addWidget(defaultImageRB);
    mainLayout->addWidget(userImageRB);
    mainLayout->addLayout(pathLayout);
    mainLayout->addLayout(buttonsLayout);
    this->setLayout(mainLayout);


}

//-----------------------------------------

void NewGameWidget::newGame()
{
    if (userImageRB->isChecked())
    imageName=&(pathLineEdit->text());
    else
        imageName = &QString("");
    this->close();
}

//-----------------------------------------

void NewGameWidget::browse()
{
    QString imageName = QFileDialog::getOpenFileName(0, tr("Open"), "","*.jpg *.jpeg *.png *.bmp");
    pathLineEdit->setText(imageName);
    this->setFocus();
}

//-----------------------------------------

NewGameWidget::~NewGameWidget()
{
    delete okButton;
    delete cancelButton;
    delete browseButton;
    delete pathLineEdit;
    delete imageName;
    delete defaultImageRB;
    delete userImageRB;
    delete mainLayout;
    delete pathLayout;
    delete buttonsLayout;
}
