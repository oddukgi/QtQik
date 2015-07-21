#ifndef GRAPH1FORM_H
#define GRAPH1FORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class Graph1Form;
}

class Graph1Form : public QWidget
{
    Q_OBJECT

public:
    explicit Graph1Form(QWidget *parent = 0);
    ~Graph1Form();

private:
    Ui::Graph1Form *ui;
};

#endif // GRAPH1FORM_H
