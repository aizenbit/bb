#include "ui.h"
#include <QDialog>
UI::UI(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400,350);
    //------------------gameMechanics---------------
    gameMechanics = new GameMechanics();
    this->setCentralWidget(gameMechanics);

    //------------------gameMenu--------------------
    gameMenu = new QMenu(tr("&Game"));

    gameMenu->addAction(tr("&New game"),
                        this,
                        SLOT(newGame()));
    gameMenu->addAction(tr("Show &image"),
                           gameMechanics,
                           SLOT(hint()));
    //------------------aboutMenu--------------------
    aboutMenu = new QMenu(tr("&About"));
    aboutMenu->addAction(tr("About the &game"),
                        this,
                        SLOT(aboutTheGame()));
    aboutMenu->addAction(tr("&Creators"),
                        this,
                        SLOT(creators()));

    //------------------menuBar----------------------
    menuBar = new QMenuBar();
    menuBar->addMenu(gameMenu);
    menuBar->addMenu(aboutMenu);
    this->setMenuBar(menuBar);

    //------------------creatorsLabel----------------
    creatorsLabel = new QLabel(tr(
                                   "<H1><CENTER>bb</CENTER></H1>"
                                   "<H2><CENTER>Gem Puzzle</CENTER></H2>"
                                   "<CENTER>The best of the best!</CENTER>"
                                   "<CENTER>Very intresting game!</CENTER>"
                                   "<CENTER>Creators: aizenbit && den5509</CENTER>"));
    creatorsLabel->setWindowTitle(tr("&Creators"));

    //------------------aboutTheGameLabel------------
    aboutTheGameLabel = new QLabel(tr(
                                       "<pre><H1><CENTER>bb</CENTER></H1>"
                                       "<H2><CENTER>Gem Puzzle</CENTER></H2>"
                                       "\tis a sliding puzzle that consists of a frame of numbered\t<br>"
                                       "\tsquare tiles in random order with one tile missing.\t<br>"
                                       "\tThe puzzle also exists in other sizes, particularly\t<br>"
                                       "\tthe smaller 8-puzzle. If the size is 3x3 tiles, the puzzle is\t<br>"
                                       "\tcalled the 8-puzzle or 9-puzzle, and if 4x4 tiles, the\t<br>"
                                       "\tpuzzle is called the 15-puzzle or 16-puzzle named, respectively,\t<br>"
                                       "\tfor the number of tiles and the number of spaces. The object\t<br>"
                                       "\tof the puzzleis to place the tiles in order by making sliding\t<br>"
                                       "\tmoves that use the empty space.\t<br>"
                                       "                                                              (c) Wiki<br><br></pre>"
                                       ));
    aboutTheGameLabel->setWindowTitle(tr("About the &game"));

    //------------------newGameWidget----------------
    newGameWidget = new NewGameWidget(gameMechanics);

    //------------------YOU_WIN---------------
    youWinLable = new QLabel(tr("<H1><FONT COLOR=\"BLUE\">Congragulations!!!!!!</H1>"
                                "<H1><FONT COLOR=\"RED\">YOU WIN!!!!</H2>"));
    connect(gameMechanics,SIGNAL(win()),youWinLable,SLOT(show()));

}

//-----------------------------------------

UI::~UI()
{
    delete gameMenu;
    delete aboutMenu;
    delete menuBar;
    delete creatorsLabel;
    delete aboutTheGameLabel;
    delete newGameWidget;
    //delete gameMechanics;
}

//-----------------------------------------

void UI::newGame()
{
     newGameWidget->show();
}

//-----------------------------------------

void UI::aboutTheGame()
{
    aboutTheGameLabel->show();
}

//-----------------------------------------

void UI::creators()
{
    creatorsLabel->show();
}

//-----------------------------------------
