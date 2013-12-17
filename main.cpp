#include "ui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator myTranslator;
    myTranslator.load("bb-" + QLocale::system().name());
    a.installTranslator(&myTranslator);
    UI w;
    w.show();

    return a.exec();
}
