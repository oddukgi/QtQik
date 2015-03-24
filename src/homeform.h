#ifndef HOMEFORM_H
#define HOMEFORM_H

#include <QWidget>

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
};

#endif // HOMEFORM_H
