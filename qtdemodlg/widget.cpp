#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushBtn_home,SIGNAL(clicked()),this,SLOT(on_pushBtn_home_clicked()));
    connect(ui->pushBtn_Graph1,SIGNAL(clicked()),this,SLOT(on_pushBtn_Graph1_clicked()));
    connect(ui->pushBtn_Graph2,SIGNAL(clicked()),this,SLOT(on_pushBtn_Graph2_clicked()));
    connect(ui->pushBtn_Schedule,SIGNAL(clicked()),this,SLOT(on_pushBtn_Schedule_clicked()));
    connect(ui->pushBtn_Value,SIGNAL(clicked()),this,SLOT(on_pushBtn_Value_clicked()));
    connect(ui->pushBtn_Raw,SIGNAL(clicked()),this,SLOT(on_pushBtn_Raw_clicked()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushBtn_home_clicked()
{

}

void Widget::on_pushBtn_Graph1_clicked()
{

}

void Widget::on_pushBtn_Graph2_clicked()
{

}

void Widget::on_pushBtn_Schedule_clicked()
{

}

void Widget::on_pushBtn_Value_clicked()
{

}

void Widget::on_pushBtn_Raw_clicked()
{

}
