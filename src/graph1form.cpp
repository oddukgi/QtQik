#include <QApplication>
#include "header.h"

Graph1Form::Graph1Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph1Form)
{
    ui->setupUi(this);
}

Graph1Form::~Graph1Form()
{
    delete ui;
}
