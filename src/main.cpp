#include <QApplication>
#include "header.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    configure configDlg;
    HttpForm httpform;
    configDlg.show();

    return a.exec();
}

// pv input 250v ~ 350v
