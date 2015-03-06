#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushBtn_1_clicked();

    void on_pushBtn_2_clicked();

    void on_pushBtn_3_clicked();

    void on_pushBtn_4_clicked();

    void on_pushBtn_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
