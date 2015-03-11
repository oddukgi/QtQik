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

  // Wrap image on buttons

    void CreateTabButtons();


private slots:
    void on_pushMin_clicked();

    void on_pushExit_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
