#include <QApplication>
#include "header.h"

/*!
    \class configure
    \brief configure class
    \inmodule qtqik

    This class is responsible for the main layout of the main widget, creates
    the gradient tab bar and the pages container
*/

/*!
    \fn configure::configure( QWidget *parent )

    Default c'tor with the \a parent QWidget as the default parameter
*/
configure::configure(QWidget *parent) :QDialog(parent), ui(new Ui::configure)
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
    ui->Accound_Label->setGeometry(712,69,41,51);
}

/*!
    Default d'tor
*/
configure::~configure()
{
    delete ui;
}

/*!
    \fn configure::CreateTabIcon( )

    Create the gradient button tab bar
*/
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

    QListWidgetItem *BtnHome = new QListWidgetItem(ui->listWidget);     // 1page 설정
    BtnHome->setText(tr("Home"));   // Home 글씨
    BtnHome->setIcon(QIcon(":/res/Img.png"));   // Home이미지

    QListWidgetItem *BtnGraph1 = new QListWidgetItem(ui->listWidget);   // 2page 설정
    BtnGraph1->setText(tr("Graph #1"));
    BtnGraph1->setIcon(QIcon(":/res/Img2.png"));

    QListWidgetItem *BtnGraph2 = new QListWidgetItem(ui->listWidget);   // 3page 설정
    BtnGraph2->setText(tr("Graph #2"));
    BtnGraph2->setIcon(QIcon(":/res/Img3.png"));

    QListWidgetItem *BtnSchedule = new QListWidgetItem(ui->listWidget); // 4page 설정
    BtnSchedule->setText(tr("Schedule"));
    BtnSchedule->setIcon(QIcon(":/res/Img4.png"));

    QListWidgetItem *BtnValue = new QListWidgetItem(ui->listWidget);    // 5page 설정
    BtnValue->setText(tr("Value Table"));
    BtnValue->setIcon(QIcon(":/res/Img5.png"));

    QListWidgetItem *BtnRaw = new QListWidgetItem(ui->listWidget);      // 6page 설정
    BtnRaw->setText(tr("Raw List"));
    BtnRaw->setIcon(QIcon(":/res/Img6.png"));

    ui->listWidget->setCurrentItem(0);

    // connect the signal for selection change
    connect(ui->listWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this,SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

}

/*!
    \fn void configure::CreateStackedPage()

    Create new pages and add them to the QStackedWidget
*/
void configure::CreateStackedPage()
{
    ui->stackedWidget->addWidget(new HomeForm);                        // 1page 만듬
    ui->stackedWidget->addWidget(new Graph1Form);                      // 2page 만듬
    ui->stackedWidget->addWidget(new Graph2Form);                      // 3page 만듬
    ui->stackedWidget->addWidget(new ScheduleForm);                    // 4page 만듬
    ui->stackedWidget->addWidget(new ValueTableForm);                  // 5page 만듬
    ui->stackedWidget->addWidget(new RawDataForm);                     // 6page 만듬
}

/*!
    \fn void configure::mousePressEvent(QMouseEvent *event)

    Handle Mouse Press Event
*/
void configure::mousePressEvent(QMouseEvent *event)
{
    m_MouseClick_X_Coordinate = event->x();
    m_MouseClick_Y_Coordinate = event->y();
}

/*!
    \fn void configure::mouseMoveEvent(QMouseEvent *event)

    Handle Mouse Move Event
*/
void configure::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX()-m_MouseClick_X_Coordinate,event->globalY()-m_MouseClick_Y_Coordinate);
}

/*!
    \fn void configure::on_PushBtn_Min_clicked()

    Window Minimize Event
*/
void configure::on_PushBtn_Min_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

/*!
    \fn void configure::on_PushBtn_Exit_clicked()

    Window Exit Event
*/
void configure::on_PushBtn_Exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        qDebug() << "Yes was clicked";
        QApplication::quit();
    }
    else
    {
        qDebug() << "No was clicked";
    }
}

/*!
    \fn void configure::changePage( QListWidgetItem *current, QListWidgetItem *previous )

    Change the page to the one on the stackedWidget that has the same index as
    the currently selected item on the tab bar QListWidget.

    We only need the \a current QListWidgetItem for getting the selected index.
    \a previous is not needed
*/
void configure::changePage(QListWidgetItem *current, QListWidgetItem* )
{
    // if current item is NULL jump to the first page
    if (!current)
    {
        ui->stackedWidget->setCurrentIndex(0);                       // Page 변환
    }
    // switch to page defined by list widget item row
    ui->stackedWidget->setCurrentIndex(ui->listWidget->row(current));
}
