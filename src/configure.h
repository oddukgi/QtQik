#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QTabBar>
#include <QMouseEvent>



QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QStackedWidget;
QT_END_NAMESPACE

namespace Ui {
class configure;
}

class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(QWidget *parent = 0);
};


class PermissionsTab : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionsTab(QWidget *parent = 0);
};





class configure : public QDialog
{
    Q_OBJECT

public:
    explicit configure(QWidget *parent = 0);
    ~configure();

private slots:
    void on_PushBtn_Min_clicked();
    void on_PushBtn_Exit_clicked();


public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:

    int m_MouseClick_X_Coordinate;
    int m_MouseClick_Y_Coordinate;

    //**  탭  만들기**//
    ///** @ 1) Tab Bar
    ///** @ 2) Stacked Widget

    void CreateListWidget();
    void CreateTabIcon();
    void CreateTabBar();
    void CreateStackedPage();

    //** frame less window mouse drag**//
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    //** close event **//
    Ui::configure *ui;

    // Create Page 6
    QStackedWidget *pagesWidget;


};


#endif // CONFIGURE_H
