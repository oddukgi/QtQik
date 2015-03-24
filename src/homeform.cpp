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

}

HomeForm::~HomeForm()
{
    delete ui;
}
