#include "newgamewidget.h"
#include "ui.h"

NewGameWidget::NewGameWidget(GameMechanics *gmMechanics, QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle(tr("New Game"));

    gameMechanics = gmMechanics;

    //------------------Buttons------------------
    okButton = new QPushButton(tr("&Ok"));
    cancelButton = new QPushButton(tr("&Cancel"));
    browseButton = new QPushButton(tr("&Browse"));

    okButton->setDisabled(true);

    //------------------RadioButtons-------------
    defaultImageRB = new QRadioButton(tr("&Default image"));
    userImageRB = new QRadioButton(tr("&User image"));
    userImageRB->setChecked(true);

    pathLineEdit = new QLineEdit();

    //----------------SpinBox---------------------
    spinBox = new QSpinBox();
    spinBox->setRange(2,8);
    spinBox->setValue(3);
    spinBoxLabel = new QLabel(tr("Choose count of  peaces:"));

    //------------------connections---------------
    connect(okButton, SIGNAL(clicked()),
            this, SLOT(newGame()));
    connect(cancelButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(browseButton, SIGNAL(clicked()),
            this, SLOT(browse()));
    connect(spinBox, SIGNAL(valueChanged(int)),
            gameMechanics, SLOT(changeLevel(int)));

    connect(defaultImageRB, SIGNAL(clicked(bool)),
            browseButton, SLOT(setDisabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)),
            browseButton, SLOT(setEnabled(bool)));

    connect(defaultImageRB, SIGNAL(clicked(bool)),
            pathLineEdit, SLOT(setDisabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)),
            pathLineEdit, SLOT(setEnabled(bool)));

    connect(defaultImageRB, SIGNAL(clicked(bool)),
            okButton, SLOT(setEnabled(bool)));
    connect(userImageRB, SIGNAL(clicked(bool)),
            okButton, SLOT(setDisabled(bool)));

    //------------------Layouts------------------
    mainLayout = new QVBoxLayout();
    buttonsLayout = new QHBoxLayout();
    pathLayout = new QHBoxLayout();
    RBLayout = new QHBoxLayout();
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    pathLayout->addWidget(pathLineEdit);
    pathLayout->addWidget(browseButton);
    RBLayout->addWidget(defaultImageRB);
    RBLayout->addWidget(userImageRB);
    mainLayout->addWidget(spinBoxLabel);
    mainLayout->addWidget(spinBox);
    mainLayout->addLayout(RBLayout);
    mainLayout->addLayout(pathLayout);
    mainLayout->addLayout(buttonsLayout);
    this->setLayout(mainLayout);
    this->setFixedSize(300, 220);
}

//-----------------------------------------

void NewGameWidget::newGame()
{
    if(pathLineEdit->text() != gameMechanics->imageName)
        gameMechanics->imageName = new QString(pathLineEdit->text());

    if (!userImageRB->isChecked())
        gameMechanics->imageName = new QString("://resources/default.jpg");

    if(!gameMechanics->imageName->isEmpty())
    {
        gameMechanics->newGame();
        pathLineEdit->clear();
    }
    this->close();
}

//-----------------------------------------

void NewGameWidget::browse()
{
    QString in = QFileDialog::getOpenFileName(0, tr("Open"), "",
                                              tr("Images") +
                                                 "(*.jpg *.jpeg *.png *.bmp"
                                                 "*.gif *.pbm *.pgm *.ppm "
                                                 "*.tiff *.xbm *.xpm);;" +
                                              tr("All Files") +
                                                 "(*.*)");

    if (in.isEmpty())
        return;
    QImage temp(in);
    if (temp.format() == QImage::Format_Invalid)
    {
        emit wrongImage();
        return;
    }
    gameMechanics->imageName = &in;
    pathLineEdit->setText(*gameMechanics->imageName);
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
    delete spinBoxLabel;
    delete pathLayout;
    delete buttonsLayout;
    delete mainLayout;
    delete gameMechanics;
}

//----------------------------------------
