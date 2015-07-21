#include <QApplication>
#include "header.h"

HttpForm::HttpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HttpForm)
{
    ui->setupUi(this);

    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
        this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 8080);
}

HttpForm::~HttpForm()
{
    delete ui;
}

void HttpForm::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    new Responder(req, resp);
}
