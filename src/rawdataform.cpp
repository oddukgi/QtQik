#include <QApplication>
#include "header.h"

RawDataForm::RawDataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RawDataForm)
{
    ui->setupUi(this);
}

RawDataForm::~RawDataForm()
{
    delete ui;
}
