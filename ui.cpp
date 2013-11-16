#include "ui.h"


UI::UI(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400,350);//устанавливаем размер окна

    Helper* helper = new Helper();
    this->setCentralWidget(helper);//устанавливаем холст по центру

    GameMechanics* gameMechanics = new GameMechanics();

    QMenu* gameMenu = new QMenu(tr("&Game"));

    gameMenu->addAction(tr("&New Game"),
                        this,
                        SLOT(newGame()),
                        Qt::CTRL + Qt::Key_N);
    gameMenu->addAction(tr("&Hint"),
                           gameMechanics,
                           SLOT(hint()),
                           Qt::CTRL + Qt::Key_H);
    gameMenu->addAction(tr("Show &Image"),
                        this,
                        SLOT(showImage()),
                        Qt::CTRL + Qt::Key_I);

    QMenu* aboutMenu = new QMenu(tr("&About"));
    aboutMenu->addAction(tr("About the &game"),
                        this,
                        SLOT(aboutTheGame()),
                        Qt::CTRL + Qt::Key_G);
    aboutMenu->addAction(tr("&Creators"),
                        this,
                        SLOT(creators()),
                        Qt::CTRL + Qt::Key_C);

    QMenuBar* menuBar = new QMenuBar();
    menuBar->addMenu(gameMenu);
    menuBar->addMenu(aboutMenu);
    this->setMenuBar(menuBar);


}

UI::~UI()
{
    delete helper;
    delete gameMenu;
    delete menuBar;
    delete gameMechanics;
    delete creatorsLabel;
}
 void UI::newGame()
 {

 }

 void UI::showImage()
 {

 }

void UI::aboutTheGame()
{

}
void UI::creators()
{
    /*
     *  К сожалению, я не понимаю, почему прога вываливается,
     *  если расположить конструктор creatorsLabel в конструкторе ui,
     *  поэтому пусть он пока побудет тут "до выяснения обстоятельств"
     */
    QLabel* creatorsLabel = new QLabel(tr(                                 
               "<H1><CENTER>bb</CENTER></H1>"
               "<H2><CENTER>Gem Puzzle</CENTER></H2>"
               "<CENTER>The best of the best!</CENTER>"
               "<CENTER>Very intresting game!</CENTER>"
               "<CENTER>Creators: aizenbit && den5509</CENTER>"));

    creatorsLabel->setFixedSize(180,130);
    creatorsLabel->show();
}
