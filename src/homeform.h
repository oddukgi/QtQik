#ifndef HOMEFORM_H
#define HOMEFORM_H

#include <QApplication>
#include "header.h"

//*** 화 면그리 기
namespace Ui {
class HomeForm;
}

class HomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit HomeForm(QWidget *parent = 0);
    ~HomeForm();
    void listwidget_update();
    void picture_update();
    void arraw_update();
    void word_update();
    void simulation_data_cal();

private slots:
    void homeform_update();

private:
    Ui::HomeForm *ui;
    QImage sourceQImage;   // 원본
    void image_set(QString filename, int x, int y);

};

#endif // HOMEFORM_H
