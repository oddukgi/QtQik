#include "homeform.h"
#include "ui_homeform.h"

HomeForm::HomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeForm)
{
    ui->setupUi(this);
}

HomeForm::~HomeForm()
{
    delete ui;
}
