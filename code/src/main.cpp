#include "confgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConfGui w;
    w.show();
    return a.exec();
}
