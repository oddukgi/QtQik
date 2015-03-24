#include <QApplication>
#include <configure.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    configure configDlg;
    configDlg.show();


    return a.exec();
}
