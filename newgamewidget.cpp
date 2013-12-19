#include "newgamewidget.h"
#include "ui.h"

NewGameWidget::NewGameWidget(GameMechanics* gmMechanics, QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle(tr("New Game"));
    gameMechanics = gmMechanics;
    imageName = gmMechanics->imageName;
    //------------------Buttons------------------
    okButton = new QPushButton(tr("&Ok"));
    cancelButton = new QPushButton(tr("&Cancel"));
    browseButton = new QPushButton(tr("&Browse"));

    //------------------RadioButtons-------------
    defaultImageRB = new QRadioButton(tr("Default image"));
    userImageRB = new QRadioButton(tr("User image"));
    userImageRB->setChecked(true);

    pathLineEdit = new QLineEdit();

    //----------------slider---------------------
    slider = new QSlider();
    slider->setRange(3,5);
    slider->setPageStep(1);
    slider->setValue(3);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setOrientation(Qt::Horizontal);
    QLabel* sliderLabel = new QLabel(tr("<pre><CENTER>Choose level:</CENTER>\n"
                                        "<CENTER>low\t     medium\thigh</CENTER><pre>"));

    //------------------connections---------------
    connect(okButton, SIGNAL(clicked()) ,this, SLOT(newGame()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));
    connect(defaultImageRB, SIGNAL(clicked(bool)), browseButton, SLOT(setDisabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)), browseButton, SLOT(setEnabled(bool)));
    connect(defaultImageRB, SIGNAL(clicked(bool)), pathLineEdit, SLOT(setDisabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)), pathLineEdit, SLOT(setEnabled(bool)));
    connect(slider, SIGNAL(valueChanged(int)), gameMechanics, SLOT(changeLevel(int)));
    //------------------Layouts------------------
    mainLayout = new QVBoxLayout();
    buttonsLayout = new QHBoxLayout();
    pathLayout = new QHBoxLayout();
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    pathLayout->addWidget(pathLineEdit);
    pathLayout->addWidget(browseButton);
    mainLayout->addWidget(sliderLabel);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(defaultImageRB);
    mainLayout->addWidget(userImageRB);
    mainLayout->addLayout(pathLayout);
    mainLayout->addLayout(buttonsLayout);
    this->setLayout(mainLayout);
    this->setFixedSize(300, 220);

}

//-----------------------------------------

void NewGameWidget::newGame()
{
    if(pathLineEdit->text() != imageName)
    {
        delete imageName;
        imageName = new QString(pathLineEdit->text());
        gameMechanics->imageName = imageName;
    }
     if (!userImageRB->isChecked())
    {
        delete imageName;
        imageName = new QString("://def");
        gameMechanics->imageName = imageName;
    }
    if(!imageName->isEmpty())
        gameMechanics->newGame();
    this->close();
}

//-----------------------------------------

void NewGameWidget::browse()
{
    QString in = QFileDialog::getOpenFileName(0, tr("Open"), "","*.jpg *.jpeg *.png *.bmp");
    if (in.isEmpty())
        return;
    imageName = &in;
    pathLineEdit->setText(*imageName);
    gameMechanics->imageName = imageName;
    newGame();

}

//-----------------------------------------

NewGameWidget::~NewGameWidget()
{
    delete okButton;
    delete cancelButton;
    delete browseButton;
    delete pathLineEdit;
    delete defaultImageRB;
    delete userImageRB;
    delete pathLayout;
    delete buttonsLayout;
    delete mainLayout;
    delete gameMechanics;
}

//----------------------------------------
