#include "ui.h"

UI::UI(QWidget *parent)
    : QMainWindow(parent)
{
    Helper* helper = new Helper();
    this->setCentralWidget(helper);//устанавливаем холст по центру

    QMenu* gameMenu = new QMenu(tr("&Game"));
    /*
     *  Теперь создаём действия для меню. Вообще-то там должен
     *  быть совсем не this, а класс, отвечающий за игровую механику,
     *  но он пока ещё не написан. Соответственно и слоты пустые.
     */
    gameMenu->addAction(tr("&New Game"),
                        this,
                        SLOT(),
                        Qt::CTRL + Qt::Key_N);
    gameMenu->addAction(tr("&Hint"),
                           this,
                           SLOT(),
                           Qt::CTRL + Qt::Key_H);
    gameMenu->addAction(tr("Show &Image"),
                        this,
                        SLOT(),
                        Qt::CTRL + Qt::Key_I);

    QMenu* aboutMenu = new QMenu(tr("&About"));
    aboutMenu->addAction(tr("About the &game"),
                        this,
                        SLOT(),
                        Qt::CTRL + Qt::Key_G);
    aboutMenu->addAction(tr("&Creators"),
                        this,
                        SLOT(),
                        Qt::CTRL + Qt::Key_C);

    QMenuBar* menuBar = new QMenuBar();
    menuBar->addMenu(gameMenu);
    menuBar->addMenu(aboutMenu);
    this->setMenuBar(menuBar);

    this->setFixedSize(400,350);//устанавливаем размер окна
}

UI::~UI()
{
    delete helper;
    delete gameMenu;
    delete menuBar;
}
