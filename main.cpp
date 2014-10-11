#include <QApplication>

#include <time.h>
#include "ui.h"


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QResource::registerResource("resources.qrc");
    srand(time(NULL));

    QApplication a(argc, argv);
    QTranslator myTranslator;
    myTranslator.load("bb-" + QLocale::system().name());
    a.installTranslator(&myTranslator);

    UI w;
    w.show(); 
    return a.exec();
}
