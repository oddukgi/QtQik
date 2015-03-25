#include "homeform.h"
#include "ui_homeform.h"
#include <QDebug>

#define IMGSOURCE ":res/bg_home.png"

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
    ui->PV_ListView->setGeometry(115,538,100,85);
    ui->PV_ListView->insertItem(0,"3,000W");
    ui->PV_ListView->insertItem(1,"150V");
    ui->PV_ListView->insertItem(2,"20A");

    // SOC list view
    ui->SOC_ListView->setGeometry(115,538,100,85);
    ui->SOC_ListView->insertItem(0,"3,000W");
    ui->SOC_ListView->insertItem(1,"150V");
    ui->SOC_ListView->insertItem(2,"20A");

    //PV Table View




}

HomeForm::~HomeForm()
{
    delete ui;
}
