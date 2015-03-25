#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    QListWidgetItem *item1 = new QListWidgetItem(ui->listWidget);
    item1->setText("Home");
    item1->setIcon( QIcon(":/icons/home.png") );

    QListWidgetItem *item2 = new QListWidgetItem(ui->listWidget);
    item2->setText("Second");
    item2->setIcon( QIcon(":/icons/graph.png") );

    QListWidgetItem *item3 = new QListWidgetItem(ui->listWidget);
    item3->setText("Third");
    item3->setIcon( QIcon(":/icons/graph.png") );

    ui->listWidget->setCurrentRow(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
