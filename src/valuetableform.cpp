#include <QApplication>
#include "header.h"

ValueTableForm::ValueTableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ValueTableForm)
{
    ui->setupUi(this);
}

ValueTableForm::~ValueTableForm()
{
    delete ui;
}
