#ifndef GRAPH2FORM_H
#define GRAPH2FORM_H

#include <QApplication>
#include "header.h"

namespace Ui {
class Graph2Form;
}

class Graph2Form : public QWidget
{
    Q_OBJECT

public:
    explicit Graph2Form(QWidget *parent = 0);
    ~Graph2Form();

private:
    Ui::Graph2Form *ui;
};

#endif // GRAPH2FORM_H
