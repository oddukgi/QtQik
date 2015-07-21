#include <QApplication>
#include "header.h"

Graph2Form::Graph2Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph2Form)
{
    ui->setupUi(this);
}

Graph2Form::~Graph2Form()
{
    delete ui;
}
