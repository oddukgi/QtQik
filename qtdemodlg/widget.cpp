#include "widget.h"
#include "ui_widget.h"

#define IMGHOME     ":/res/Img1.png"
#define IMGGRAPH_1  ":/res/Img2.png"
#define IMGGRAPH_2  ":/res/Img3.png"
#define IMGSCHEDULE ":/res/Img4.png"
#define IMGVALUE    ":/res/Img5.png"
#define IMGRAW      ":/res/Img6.png"


// Creat Tab Controls

class MyTabWidget:public QTabWidget
{
public:
    MyTabWidget(QWidget* parent = 0):QTabWidget(parent)
    {
      setParent(parent);
    }

    //Overridden method from QTabWidget
    QTabBar* tabBar()
    {
      return QTabWidget::tabBar();
    }
};



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    CreateTabButtons();

}

void Widget::CreateTabButtons()
{
  QPixmap pix_1(IMGHOME);
  QIcon icon_1(pix_1);

  ui->pushBtn_Home->setIcon(icon_1);
  ui->pushBtn_Home->setIconSize(pix_1.rect().size());
  ui->pushBtn_Home->setFixedSize(pix_1.rect().size());


  QPixmap pix_2(IMGGRAPH_1);
  QIcon icon_2(pix_2);

  ui->pushBtn_Graph1->setIcon(icon_2);
  ui->pushBtn_Graph1->setIconSize(pix_2.rect().size());
  ui->pushBtn_Graph1->setFixedSize(pix_2.rect().size());

  QPixmap pix_3(IMGGRAPH_2);
  QIcon icon_3(pix_3);

  ui->pushBtn_Graph2->setIcon(icon_3);
  ui->pushBtn_Graph2->setIconSize(pix_3.rect().size());
  ui->pushBtn_Graph2->setFixedSize(pix_3.rect().size());


  QPixmap pix_4(IMGSCHEDULE);
  QIcon icon_4(pix_4);

  ui->pushBtn_Schedule->setIcon(icon_4);
  ui->pushBtn_Schedule->setIconSize(pix_4.rect().size());
  ui->pushBtn_Schedule->setFixedSize(pix_4.rect().size());


  QPixmap pix_5(IMGVALUE);
  QIcon icon_5(pix_5);

  ui->pushBtn_Value->setIcon(icon_5);
  ui->pushBtn_Value->setIconSize(pix_5.rect().size());
  ui->pushBtn_Value->setFixedSize(pix_5.rect().size());


  QPixmap pix_6(IMGRAW);
  QIcon icon_6(pix_6);

  ui->pushBtn_Raw->setIcon(icon_6);
  ui->pushBtn_Raw->setIconSize(pix_6.rect().size());
  ui->pushBtn_Raw->setFixedSize(pix_6.rect().size());



}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushMin_clicked()
{
    QWidget::setWindowState(Qt::WindowMinimized);
}

void Widget::on_pushExit_clicked()
{
  QWidget::close();
}


