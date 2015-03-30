#include "homeform.h"
#include "ui_homeform.h"
#include <QDebug>

#define IMGSOURCE ":res/bg_home.png"


/*!
    \class HomeForm
    \brief HomeForm class
    \inmodule qtqik

    Create ListView  on screen

*/



HomeForm::HomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeForm)
{
    ui->setupUi(this);
    sourceQImage = QImage(IMGSOURCE);
   ui->Img_Label->setGeometry(0,0,1024,660);

    QPixmap drawPixmap = QPixmap::fromImage(sourceQImage);
    ui->Img_Label->setPixmap(drawPixmap.scaled(ui->Img_Label->size())); //source image

    // PV list view
    ui->PV_ListView->setGeometry(122,438,100,63);
    ui->PV_ListView->insertItem(0,"3,000W");
    ui->PV_ListView->insertItem(1,"150V");
    ui->PV_ListView->insertItem(2,"20A");

    // SOC list view
    ui->SOC_ListView->setGeometry(448,438,100,63);
    ui->SOC_ListView->insertItem(0,"3,000W");
    ui->SOC_ListView->insertItem(1,"150V");
    ui->SOC_ListView->insertItem(2,"20A");

    //Grid list View
    ui->Grid_ListView->setGeometry(859,103,100,63);
    ui->Grid_ListView->insertItem(0,"3,000W");
    ui->Grid_ListView->insertItem(1,"150V");
    ui->Grid_ListView->insertItem(2,"20A");

    //Load list view
    ui->Load_ListView->setGeometry(856,438,100,63);
    ui->Load_ListView->insertItem(0,"3,000W");
    ui->Load_ListView->insertItem(1,"150V");
    ui->Load_ListView->insertItem(2,"20A");


}

HomeForm::~HomeForm()
{
    delete ui;
}
