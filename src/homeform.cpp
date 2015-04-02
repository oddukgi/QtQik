#include "homeform.h"
#include "ui_homeform.h"
#include <QDebug>
#include <QtGui>
#include <QApplication>
#include "listviewdelegate.h"


#define IMGSOURCE ":res/bg_home.png"

/*!
    \class HomeForm
    \brief HomeForm class
    \inmodule qtqik

    Create ListView on screen

    Constant         | Value   |	Description
    ------------------------------------------------------------------------------
    Qt::DisplayRole  |   0     |  The key data to be rendered in the form of text.(QString)
    Qt::UserRole	   |  0x0100 |  The first role that can be used for application-specific purposes.
*/

/*!
    Default constructor with \a parent as the default argument
*/
HomeForm::HomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeForm)
{
    ui->setupUi(this);
    sourceQImage = QImage(IMGSOURCE);

    //Put Background Image
    ui->Img_Label->setGeometry(0,0,1024,660);

    QPixmap drawPixmap = QPixmap::fromImage(sourceQImage);

    // source image
    ui->Img_Label->setPixmap(drawPixmap.scaled(ui->Img_Label->size()));


    ListviewDelegate *m_listdelegate;
    m_listdelegate = new ListviewDelegate();

    ui->ListWideget1->setItemDelegate(new ListviewDelegate(ui->ListWideget1));
    QListWidgetItem *item1 = new QListWidgetItem();
    item1->setData(Qt::DisplayRole, "3,000W");

    QListWidgetItem *item2 = new QListWidgetItem();
    item2->setData(Qt::DisplayRole, "150V");

    QListWidgetItem *item3 = new QListWidgetItem();
    item3->setData(Qt::DisplayRole, "20A");


    ui->ListWideget1->setGeometry(118,438,150,104);
    ui->ListWideget1->insertItem(0,item1);
    ui->ListWideget1->insertItem(1,item2);
    ui->ListWideget1->insertItem(2,item3);

    // Position
    // PV list view
    //  ui->PV_ListView->setGeometry(122,438,200,100);
    // SOC list view
    //  ui->SOC_ListView->setGeometry(448,438,100,63);
    // Grid list View
    //  ui->Grid_ListView->setGeometry(859,103,100,63);
    // Load list view
    //  ui->Load_ListView->setGeometry(856,438,100,63);

    // Grid list View
    //ui->Grid_ListView->setGeometry(859,103,100,63);
    //ui->Grid_ListView->insertItem(0,"3,000W");
    //ui->Grid_ListView->insertItem(1,"150V");
    //ui->Grid_ListView->insertItem(2,"20A");

    // Load list view
    //ui->Load_ListView->setGeometry(856,438,100,63);
    //ui->Load_ListView->insertItem(0,"3,000W");
    //ui->Load_ListView->insertItem(1,"150V");
    //ui->Load_ListView->insertItem(2,"20A");
}

/*!
    Default destructor
*/
HomeForm::~HomeForm()
{
    delete ui;
}
