// Для Qt4:
#include <QApplication>

#include <time.h>
#include "ui.h"


int main(int argc, char *argv[])
{
    QResource::registerResource("resources.qrc");
    srand(time(NULL));

    /*QCoreApplication::addLibraryPath("platforms");
    QCoreApplication::addLibraryPath("plugins/platforms");
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + "/plugins/platforms/");
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + "/platforms/");*/

    QApplication a(argc, argv);
    QTranslator myTranslator;
    myTranslator.load("bb-" + QLocale::system().name());
    a.installTranslator(&myTranslator);
    /*a.addLibraryPath("platforms");
    a.addLibraryPath("plugins/platforms");
    a.addLibraryPath(QCoreApplication::applicationDirPath() + "/plugins/platforms/");
    a.addLibraryPath(QCoreApplication::applicationDirPath() + "/platforms/");*/
    UI w;
    w.show(); 
    return a.exec();
}
