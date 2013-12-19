#include "ui.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    srand(5);
    QApplication a(argc, argv);
    QTranslator myTranslator;
    myTranslator.load("bb-" + QLocale::system().name());
    a.installTranslator(&myTranslator);
    UI w;
    w.show();

    return a.exec();
}
