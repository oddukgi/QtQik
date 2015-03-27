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
    ui->listWidget->setStyle( new MyNoFocusStyle );

    QPalette palette = qApp->palette();

    QLinearGradient buttonGradient(0,0,0,ui->listWidget->height());
    buttonGradient.setColorAt(0,QColor(50,100,200));
    buttonGradient.setColorAt(1,QColor(40,60,120));

    palette.setBrush( QPalette::Base, buttonGradient );
    palette.setBrush( QPalette::Highlight, buttonGradient );
    palette.setBrush( QPalette::HighlightedText, Qt::white );
    palette.setBrush( QPalette::Text, Qt::white );
    ui->listWidget->setPalette(palette);
    ui->listWidget->setStyleSheet("border: none; font-weight: bold;");

    QListWidgetItem *BtnHome = new QListWidgetItem(ui->listWidget);
    BtnHome->setText(tr("Home"));
    BtnHome->setIcon(QIcon(":/res/Img.png"));

    QListWidgetItem *BtnGraph1 = new QListWidgetItem(ui->listWidget);
    BtnGraph1->setText(tr("Graph #1"));
    BtnGraph1->setIcon(QIcon(":/res/Img2.png"));

    QListWidgetItem *BtnGraph2 = new QListWidgetItem(ui->listWidget);
    BtnGraph2->setText(tr("Graph #2"));
    BtnGraph2->setIcon(QIcon(":/res/Img3.png"));

    QListWidgetItem *BtnSchedule = new QListWidgetItem(ui->listWidget);
    BtnSchedule->setText(tr("Schedule"));
    BtnSchedule->setIcon(QIcon(":/res/Img4.png"));

    QListWidgetItem *BtnValue = new QListWidgetItem(ui->listWidget);
    BtnValue->setText(tr("Value Table"));
    BtnValue->setIcon(QIcon(":/res/Img5.png"));

    QListWidgetItem *BtnRaw = new QListWidgetItem(ui->listWidget);
    BtnRaw->setText(tr("Raw List"));
    BtnRaw->setIcon(QIcon(":/res/Img6.png"));

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

