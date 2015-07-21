#ifndef SERIALFORM_H
#define SERIALFORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class SerialForm;
}

class SerialForm : public QWidget
{
    Q_OBJECT

public:
    explicit SerialForm(QWidget *parent = 0);
    ~SerialForm();

private slots:
    void doYourThing();
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();
    void handleError(QSerialPort::SerialPortError error);

private:
    Ui::SerialForm *ui;
    void initActionsConnections();
    QSerialPort *serial;

};

extern MAIN_INFO g_MAIN_INFO;
extern MAIN_CONTROL g_MAIN_CONTROL;

extern bool g_time_write_enable;
extern bool g_schedule_write_enable;
extern bool g_dr_write_enable;


#endif // SERIALFORM_H
