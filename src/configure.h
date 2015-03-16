#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QTabBar>

namespace Ui {
class configure;
}

//! [0]
class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(QWidget *parent = 0);
};
//! [0]


//! [1]
class PermissionsTab : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionsTab(QWidget *parent = 0);
};
//! [1]




class configure : public QDialog
{
    Q_OBJECT

public:
    explicit configure(QWidget *parent = 0);
    ~configure();

private:

    void CreateTabIcon();
    void CreateTabBar();
    Ui::configure *ui;
};

#endif // CONFIGURE_H
