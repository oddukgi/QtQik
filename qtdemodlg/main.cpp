#include "widget.h"
#include <QApplication>
//| Qt::FramelessWindowHint
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setWindowFlags(Qt::Window );
    w.show();

    return a.exec();
}
