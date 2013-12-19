#include "ui.h"
#include <QApplication>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QTranslator myTranslator;
    myTranslator.load("bb-" + QLocale::system().name());
    a.installTranslator(&myTranslator);
    UI w;
    w.show();

    return a.exec();
}
