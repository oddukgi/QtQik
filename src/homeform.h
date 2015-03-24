#ifndef HOMEFORM_H
#define HOMEFORM_H

#include <QWidget>
#include <QImage>

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

private:
    Ui::HomeForm *ui;
    QImage sourceQImage;   // 원본
};

#endif // HOMEFORM_H
