#include "configure.h"
#include "ui_configure.h"
#include "testtabbar.h"

configure::configure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configure)
{
    ui->setupUi(this);
    CreateTabBar();
 //   CreateTabIcon();
}

configure::~configure()
{
    delete ui;
}







void configure::CreateTabBar()
{

    // Use TabWidget, Make Tab
    TestTabWidget* test = new TestTabWidget(this);
     test->setGeometry(20, 20, 300, 200);


     test->addTab(new QWidget(), QIcon(":/res/Img.png"), "");
     test->addTab(new QWidget(), QIcon(":/res/Img2.png"), "");
     test->setTabPosition(QTabWidget::North);


}

/*void configure::CreateTabIcon()
{
    QListWidgetItem *BtnHome = new QListWidgetItem(ui->listWidget);
    BtnHome->setIcon(QIcon(":/res/Img.png"));
    BtnHome->setTextAlignment(Qt::AlignVCenter);
    BtnHome->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *BtnGraph1 = new QListWidgetItem(ui->listWidget);
    BtnGraph1->setIcon(QIcon(":/res/Img2.png"));
    BtnGraph1->setTextAlignment(Qt::AlignVCenter);
    BtnGraph1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *BtnGraph2 = new QListWidgetItem(ui->listWidget);
    BtnGraph2->setIcon(QIcon(":/res/Img3.png"));
    BtnGraph2->setTextAlignment(Qt::AlignVCenter);
    BtnGraph2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *BtnSchedule = new QListWidgetItem(ui->listWidget);
    BtnSchedule->setIcon(QIcon(":/res/Img4.png"));
    BtnSchedule->setTextAlignment(Qt::AlignVCenter);
    BtnSchedule->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *BtnValue = new QListWidgetItem(ui->listWidget);
    BtnValue->setIcon(QIcon(":/res/Img5.png"));
    BtnValue->setTextAlignment(Qt::AlignVCenter);
    BtnValue->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *BtnRaw = new QListWidgetItem(ui->listWidget);
    BtnRaw->setIcon(QIcon(":/res/Img6.png"));
    BtnRaw->setTextAlignment(Qt::AlignVCenter);
    BtnRaw->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

}
*/
