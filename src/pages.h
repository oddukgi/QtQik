#ifndef PAGES_H
#define PAGES_H

#include <QWidget>
#include <QImage>

//** @ 6 Pages
//** Home,Graph1, Graph2, Schedule,
//** Value Table, Raw List


// create on 2015.03.23, Mon

class CHomePage : public QWidget
{
public:
    CHomePage(QWidget *parent = 0);

private:
    QImage sourceQImage; //원본
  // display on view
};

class CGraph1Page : public QWidget
{
 public:
    CGraph1Page(QWidget *parent = 0);

};

class CGraph2Page : public QWidget
{
public:
    CGraph2Page(QWidget *parent = 0);

};

class CSchedulePage: public QWidget
{
public:
    CSchedulePage(QWidget *parent = 0);

};

class CValueTablePage : public QWidget
{
public:
    CValueTablePage(QWidget *parent = 0);

};

class CRawPage : public QWidget
{
public:
    CRawPage(QWidget *parent = 0);

};


#endif // PAGES_H
