#ifndef RAWDATAFORM_H
#define RAWDATAFORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class RawDataForm;
}

class RawDataForm : public QWidget
{
    Q_OBJECT

public:
    explicit RawDataForm(QWidget *parent = 0);
    ~RawDataForm();

private:
    Ui::RawDataForm *ui;
};

#endif // RAWDATAFORM_H
