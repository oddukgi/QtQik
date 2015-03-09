#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushBtn_home_clicked();

    void on_pushBtn_Graph1_clicked();

    void on_pushBtn_Graph2_clicked();

    void on_pushBtn_Schedule_clicked();

    void on_pushBtn_Value_clicked();

    void on_pushBtn_Raw_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
