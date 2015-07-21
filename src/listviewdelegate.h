/*
* ListViewDelegate.h
*
* Created on : April 2,2015
* Author : darongyi77.tistory.com
*/

#ifndef LISTVIEWDELEGATE_H
#define LISTVIEWDELEGATE_H

#include <QApplication>
#include "header.h"

/*
 * To make delegate class, need to override couple of functions,
1) sizeHint(const QStyleOptionViewItem & option ,const QModelIndex & index) const
2) sizeHint return you the item width. Which can be either predefined or you can calculate it using the data elements.
3) paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const
*/


class ListviewDelegate : public QAbstractItemDelegate
{
public:

    enum datarole { HeaderRole = Qt::UserRole + 100, SubheaderRole};

    ListviewDelegate(QObject *parent = 0);


    // Paint Listview
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    // Set Listview Size
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

    ~ListviewDelegate();
};

#endif // LISTVIEWDELEGATE_H
