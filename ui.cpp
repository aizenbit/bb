#include "ui.h"

UI::UI(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400,350);

    //------------------gameMechanics---------------
    gameMechanics = new GameMechanics();
    this->setCentralWidget(gameMechanics);

    //------------------gameMenu--------------------
    gameMenu = new QMenu(tr("&Game"));

    gameMenu->addAction(tr("&New Game"),
                        this,
                        SLOT(newGame()));
    gameMenu->addAction(tr("&Hint"),
                           gameMechanics,
                           SLOT(hint()));
    gameMenu->addAction(tr("Show &Image"),
                        this,
                        SLOT(showImage()));

    //------------------aboutMenu--------------------
    aboutMenu = new QMenu(tr("&About"));
    aboutMenu->addAction(tr("About the game"),
                        this,
                        SLOT(aboutTheGame()));
    aboutMenu->addAction(tr("Creators"),
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
    creatorsLabel->setFixedSize(180,130);
    creatorsLabel->setWindowTitle(tr("Creators"));

    //------------------aboutTheGameLabel------------
    aboutTheGameLabel = new QLabel(tr(
                                       "<H1><CENTER>bb</CENTER></H1>"
                                       "<H2><CENTER>Gem Puzzle</CENTER></H2>"
                                       "<pre>    is a sliding puzzle that consists of a frame of numbered<br>"
                                       "    square tiles in random order with one tile missing.<br>"
                                       "    The puzzle also exists in other sizes, particularly<br>"
                                       "    the smaller 8-puzzle. If the size is 3×3 tiles, the puzzle is<br>"
                                       "    called the 8-puzzle or 9-puzzle, and if 4×4 tiles, the<br>"
                                       "    puzzle is called the 15-puzzle or 16-puzzle named, respectively,<br>"
                                       "    for the number of tiles and the number of spaces. The object<br>"
                                       "    of the puzzleis to place the tiles in order by making sliding<br>"
                                       "    moves that use the empty space.<br>"
                                       "                                                              (c) Wiki</pre>"
                                       ));
    aboutTheGameLabel->setFixedWidth(568);
    aboutTheGameLabel->setWindowTitle(tr("About The Game"));

    //------------------newGameWidget----------------
    newGameWidget = new NewGameWidget(gameMechanics->imageName);


}

//-----------------------------------------

UI::~UI()
{
    delete gameMenu;
    delete aboutMenu;
    delete menuBar;
    delete gameMechanics;
    delete creatorsLabel;
    delete aboutTheGameLabel;
    delete newGameWidget;
}

//-----------------------------------------

void UI::newGame()
{
     newGameWidget->show();
}

//-----------------------------------------

void UI::showImage()
{

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
