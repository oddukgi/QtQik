#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui-,SIGNAL(clicked()),this,SLOT(slotPushbutton()));
    connect(ui->pushButton1, SIGNAL(clicked()),this,SLOT(slotPushbutton1()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBtn_1_clicked()
{

}

void MainWindow::on_pushBtn_2_clicked()
{

}

void MainWindow::on_pushBtn_3_clicked()
{

}

void MainWindow::on_pushBtn_4_clicked()
{

}

void MainWindow::on_pushBtn_5_clicked()
{

}
