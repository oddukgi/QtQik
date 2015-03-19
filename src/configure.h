#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QTabBar>
#include <QMouseEvent>

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

private:

    int m_MouseClick_X_Coordinate;
    int m_MouseClick_Y_Coordinate;

    //**  탭  만들기**//
    ///** @ 1) Create Tab Bar
    ///** @ 2) Create Stacked Widget
    void CreateTabIcon();
    void CreateTabBar();

    //** frame less window mouse drag**//
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    //** close event **//
   // void closeEvent (QCloseEvent *event);
    Ui::configure *ui;
};

#endif // CONFIGURE_H
