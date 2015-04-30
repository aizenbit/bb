#include <QDialog>

#include "ui.h"

UI::UI(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800,700);

    //------------------gameMechanics---------------
    gameMechanics = new GameMechanics();
    this->setCentralWidget(gameMechanics);

    //------------------newGameWidget----------------
    newGameWidget = new NewGameWidget(gameMechanics);
    connect(newGameWidget, SIGNAL(wrongImage()),
            this, SLOT(showErrorBox()));

    //------------------gameMenu--------------------
    gameMenu = new QMenu(tr("&Game"));
    gameMenu->addAction(tr("&New game"),
                        newGameWidget,
                        SLOT(show()));
    gameMenu->addAction(tr("Show &image"),
                        gameMechanics,
                        SLOT(showImage()));

    //------------------aboutMenu--------------------
    aboutMenu = new QMenu(tr("&About"));
    aboutMenu->addAction(tr("About the &game"),
                        this,
                        SLOT(showAboutBox()));
    aboutMenu->addAction(tr("&Creators"),
                        this,
                        SLOT(showCreatorsBox()));

    //------------------menuBar----------------------
    menuBar = new QMenuBar();
    menuBar->addMenu(gameMenu);
    menuBar->addMenu(aboutMenu);
    this->setMenuBar(menuBar);

    //------------------YOU_WIN---------------
    youWinLable = new QLabel(tr("<H1><FONT COLOR=\"BLUE\">Congragulations!!!!!!</H1>"
                                "<H1><FONT COLOR=\"RED\">YOU WIN!!!!</H2>"));
    youWinLable->setWindowTitle(tr("YOU WIN!"));
    connect(gameMechanics, SIGNAL(win()),
            youWinLable, SLOT(show()));
}

//-----------------------------------------

UI::~UI()
{
    delete gameMenu;
    delete aboutMenu;
    delete menuBar;
    delete youWinLable;
    delete newGameWidget;
}

//-----------------------------------------

void UI::showAboutBox()
{
    QMessageBox aboutBox;
    aboutBox.setWindowTitle(tr("About"));
    aboutBox.setInformativeText(tr(
                                    "<pre><H1><CENTER>bb</CENTER></H1>"
                                    "<H2><CENTER>Gem Puzzle</CENTER></H2>"
                                    "is a sliding puzzle that consists of a frame of numbered\t<br>"
                                    "square tiles in random order with one tile missing.\t<br>"
                                    "The puzzle also exists in other sizes, particularly\t<br>"
                                    "the smaller 8-puzzle. If the size is 3x3 tiles, the puzzle is\t<br>"
                                    "called the 8-puzzle or 9-puzzle, and if 4x4 tiles, the\t<br>"
                                    "puzzle is called the 15-puzzle or 16-puzzle named, respectively,\t"
                                    "for the number of tiles and the number of spaces. The object\t<br>"
                                    "of the puzzleis to place the tiles in order by making sliding\t<br>"
                                    "moves that use the empty space.\t<br>"
                                    "                                                              (c) Wiki<br><br></pre>"
                                    ));
    aboutBox.exec();
}

//-----------------------------------------

void UI::showCreatorsBox()
{
    QMessageBox creatorsBox;
    creatorsBox.setWindowTitle(tr("Creators"));
    creatorsBox.setInformativeText(tr("<H1><CENTER>bb</CENTER></H1>"
                                "<H2><CENTER>Gem Puzzle</CENTER></H2>"
                                "<CENTER>The best of the best!</CENTER>"
                                "<CENTER>Very intresting game!</CENTER>"
                                "<CENTER>Creators: aizenbit && den5509</CENTER>"
                                "<CENTER>Repo: <A HREF=https://github.com/aizenbit/bb>"
                                        "https://github.com/aizenbit/bb</A></CENTER>"));
    creatorsBox.exec();
}

//-----------------------------------------

void UI::showErrorBox()
{
    QMessageBox errorBox;
    errorBox.setWindowTitle(tr("Error"));
    errorBox.setInformativeText(tr("Image is invalid! Try to load another image."));
    errorBox.exec();
}

//-----------------------------------------
