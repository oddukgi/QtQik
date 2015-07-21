#include <QApplication>
#include "header.h"

/*
 * ListviewDelegate.cpp
 *
 *  Created on: April 2, 2015
 *  Author: http://darongyi77.tistory.com
 */

//QSize ListviewDelegate::iconSize = QSize(60,60);
//int ListviewDelegate::padding =5;

ListviewDelegate::ListviewDelegate(QObject *parent)
{

}


//QStyledItemDelegate
//display and editing facilities for data items from a model.

void ListviewDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QRect r = option.rect;

    //Color: #C4C4C4
    QPen linePen(QColor::fromRgb(211,211,211), 1, Qt::SolidLine);

    //Color: #005A83
    QPen lineMarkedPen(QColor::fromRgb(0,90,131), 1, Qt::SolidLine);

    //Color: #333
    QPen fontPen(QColor::fromRgb(51,51,51), 1, Qt::SolidLine);

    //Color: #fff
    QPen fontMarkedPen(Qt::white, 1, Qt::SolidLine);

    if(option.state & QStyle::State_Selected)
    {
      QLinearGradient gradientSelected(r.left(),r.top(),r.left(),r.height()+r.top());
      gradientSelected.setColorAt(0.0, QColor::fromRgb(119,213,247));
      gradientSelected.setColorAt(0.9, QColor::fromRgb(27,134,183));
      gradientSelected.setColorAt(1.0, QColor::fromRgb(0,120,174));
      painter->setBrush(gradientSelected);
      painter->drawRect(r);

      //BORDER
      painter->setPen(lineMarkedPen);
      painter->drawLine(r.topLeft(),r.topRight());
      painter->drawLine(r.topRight(),r.bottomRight());
      painter->drawLine(r.bottomLeft(),r.bottomRight());
      painter->drawLine(r.topLeft(),r.bottomLeft());

      painter->setPen(fontMarkedPen);

      } else {
            //BACKGROUND
            //ALTERNATING COLORS
            painter->setBrush( (index.row() % 2) ? Qt::white : QColor(252,252,252) );
            painter->drawRect(r);

            //BORDER
            painter->setPen(linePen);
            painter->drawLine(r.topLeft(),r.topRight());
            painter->drawLine(r.topRight(),r.bottomRight());
            painter->drawLine(r.bottomLeft(),r.bottomRight());
            painter->drawLine(r.topLeft(),r.bottomLeft());

            painter->setPen(fontPen);
        }

        //GET TITLE, DESCRIPTION AND ICON
        QIcon ic = QIcon(qvariant_cast<QPixmap>(index.data(Qt::DecorationRole)));
        QString title = index.data(Qt::DisplayRole).toString();
      //  QString description = index.data(Qt::UserRole + 1).toString();

        int imageSpace = 10;
        if (!ic.isNull()) {
            //ICON
            r = option.rect.adjusted(5, 10, -10, -10);
            ic.paint(painter, r, Qt::AlignVCenter|Qt::AlignLeft);
            //imageSpace = 55;

        }

        //TITLE
        r = option.rect.adjusted(imageSpace, 0, -10, -10);
        painter->setFont( QFont( "Lucida Grande",11, QFont::Bold ) );
        painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignBottom|Qt::AlignLeft, title, &r);

        //DESCRIPTION
//        r = option.rect.adjusted(imageSpace, 30, -10, 0);
//        painter->setFont( QFont( "Lucida Grande", 5, QFont::Bold ) );
//        painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignLeft, description, &r);
}


//allocate each item size in listview
QSize ListviewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
   // whatever..
  return QSize(200, 34); // very dumb value
}


ListviewDelegate::~ListviewDelegate()
{

}
