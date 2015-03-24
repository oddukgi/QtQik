#include "configure.h"
#include "ui_configure.h"
#include "testtabbar.h"
#include <QMessageBox>
#include <QDebug>

#include "homeform.h"
#include "pages.h"

#define APP_NAME "QtQikDemo"

//contentsWidget

configure::configure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configure)
{
    ui->setupUi(this);

    CreateStackedPage();
    CreateTabIcon();

     ui->listWidget->setCurrentRow(0);

    //**  투명 윈도우 만들기 **//
    //this->setAttribute(Qt::WA_TranslucentBackground, true);
    //**  테두리 없는 윈도우  만듬**//
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    // Set Label Pos
    ui->Accound_Label->setGeometry(725,69,41,51);

}

configure::~configure()
{
    delete ui;
}


void configure::CreateTabBar()
{

    // Use TabWidget, Make Tab
    TestTabWidget* test = new TestTabWidget(this);
    test->setGeometry(20, 20, 800, 300);

//    test->setStyleSheet(
//                         "QTabBar::tab:selected { background: lightgray; } "
//                         "QTabWidget::pane { border: 0; } "
//                         "QTabBar::tab:first:selected { background: url(:/images/common/Imgpush_1.jpg) }"
//                         );

    test->addTab(new QWidget(), QIcon(":/res/Img.png"), "");
    test->addTab(new QWidget(), QIcon(":/res/Img2.png"), "");
    test->addTab(new QWidget(), QIcon(":/res/Img3.png"), "");
    test->addTab(new QWidget(), QIcon(":/res/Img4.png"), "");
    test->addTab(new QWidget(), QIcon(":/res/Img5.png"), "");
    test->addTab(new QWidget(), QIcon(":/res/Img6.png"), "");


    test->setTabPosition(QTabWidget::North);



}

void configure::CreateTabIcon()
{

    QListWidgetItem *BtnHome = new QListWidgetItem(ui->listWidget);
    BtnHome->setIcon(QIcon(":/res/Img.png"));
  //BtnHome->setTextAlignment(Qt::AlignLeft);
    BtnHome->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    BtnHome->setSizeHint(QSize(94, 51));

    QListWidgetItem *BtnGraph1 = new QListWidgetItem(ui->listWidget);
    BtnGraph1->setIcon(QIcon(":/res/Img2.png"));
   // BtnGraph1->setTextAlignment(Qt::AlignLeft);
    BtnGraph1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    BtnGraph1->setSizeHint(QSize(113,51));

    QListWidgetItem *BtnGraph2 = new QListWidgetItem(ui->listWidget);
    BtnGraph2->setIcon(QIcon(":/res/Img3.png"));
 // BtnGraph2->setTextAlignment(Qt::AlignLeft);
    BtnGraph2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    BtnGraph2->setSizeHint(QSize(113,51));

    QListWidgetItem *BtnSchedule = new QListWidgetItem(ui->listWidget);
    BtnSchedule->setIcon(QIcon(":/res/Img4.png"));
   // BtnSchedule->setTextAlignment(Qt::AlignLeft);
    BtnSchedule->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    BtnSchedule->setSizeHint(QSize(115,51));

    QListWidgetItem *BtnValue = new QListWidgetItem(ui->listWidget);
    BtnValue->setIcon(QIcon(":/res/Img5.png"));
  //  BtnValue->setTextAlignment(Qt::AlignVCenter);
    BtnValue->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    BtnValue->setSizeHint(QSize(129,51));

    QListWidgetItem *BtnRaw = new QListWidgetItem(ui->listWidget);
    BtnRaw->setIcon(QIcon(":/res/Img6.png"));
 //   BtnRaw->setTextAlignment(Qt::AlignVCenter);
    BtnRaw->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    BtnRaw->setSizeHint(QSize(111,51));


    ui->listWidget->setCurrentItem(0);

    // Signal-Slot

    connect(ui->listWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this,SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

}


//** Home,Graph1, Graph2, Schedule,
//** Value Table, Raw List

void configure::CreateStackedPage()
{
 //  pagesWidget = new QStackedWidget(ui->stackedWidget);
   ui->stackedWidget->addWidget(new HomeForm);
   ui->stackedWidget->addWidget(new CGraph1Page);
   ui->stackedWidget->addWidget(new CGraph2Page);
   ui->stackedWidget->addWidget(new CSchedulePage);
   ui->stackedWidget->addWidget(new CValueTablePage);
   ui->stackedWidget->addWidget(new CRawPage);

}


//**Mouse Drage Event **//
void configure::mousePressEvent(QMouseEvent *event)
{
  m_MouseClick_X_Coordinate = event->x();
  m_MouseClick_Y_Coordinate = event->y();

}

void configure::mouseMoveEvent(QMouseEvent *event)
{
   move(event->globalX()-m_MouseClick_X_Coordinate,event->globalY()-m_MouseClick_Y_Coordinate);
}


//** Window Minimize N Exit Event **//
void configure::on_PushBtn_Min_clicked()
{
   setWindowState(Qt::WindowMinimized);
}


void configure::on_PushBtn_Exit_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Test", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        QApplication::quit();
      } else {
        qDebug() << "No was clicked";
      }
}





void configure::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    // 임시방

    ui->stackedWidget->setCurrentIndex(ui->listWidget->row(current));
}

