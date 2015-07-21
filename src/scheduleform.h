#ifndef SCHEDULEFORM_H
#define SCHEDULEFORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class ScheduleForm;
}

class ScheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleForm(QWidget *parent = 0);
    ~ScheduleForm();

private slots:
    void schedule_set_textbox_init();
    void main_time_update();
    void check();
    void on_pushButton_set_clicked();

private:
    Ui::ScheduleForm *ui;
    QImage scheduleImage;   // 원본
    void time_check();
    void schedule_check();
    void dr_check();
};

#endif // SCHEDULEFORM_H
