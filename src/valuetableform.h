#ifndef VALUETABLEFORM_H
#define VALUETABLEFORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class ValueTableForm;
}

class ValueTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit ValueTableForm(QWidget *parent = 0);
    ~ValueTableForm();

private:
    Ui::ValueTableForm *ui;
};

#endif // VALUETABLEFORM_H
