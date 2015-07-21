#ifndef HTTPFORM_H
#define HTTPFORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class HttpForm;
}

class HttpForm : public QWidget
{
    Q_OBJECT

public:
    explicit HttpForm(QWidget *parent = 0);
    ~HttpForm();

private slots:
    void handleRequest(QHttpRequest *req, QHttpResponse *resp);

private:
    Ui::HttpForm *ui;
};

#endif // HTTPFORM_H
