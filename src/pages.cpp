#include <QtWidgets>
#include "pages.h"

#define IMGHOME_BG ":res/bg_home.png"

CHomePage::CHomePage(QWidget *parent)
    : QWidget(parent)
{
//  //QLabel
//  QLabel *pLabelStatus = new QLabel;
//  pLabelStatus->setGeometry(0,0,1024,660);
//  // Put Image Background on QLabel

//  sourceQImage = QImage(IMGHOME_BG);
//  QPixmap drawPixmap = QPixmap::fromImage(sourceQImage);
//  pLabelStatus->setPixmap(drawPixmap.scaled(pLabelStatus->size())); //source image

  QLabel *serverLabel = new QLabel(tr("Server:"));
  qDebug("load bg_home image ");
}



CGraph1Page::CGraph1Page(QWidget *parent)
    : QWidget(parent)
{

}



CGraph2Page::CGraph2Page(QWidget *parent)
    : QWidget(parent)
{

}



CSchedulePage::CSchedulePage(QWidget *parent)
    : QWidget(parent)
{

}



CValueTablePage::CValueTablePage(QWidget *parent)
    : QWidget(parent)
{

}

CRawPage::CRawPage(QWidget *parent)
    : QWidget(parent)
{

}
