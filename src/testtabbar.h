#ifndef TESTTABBAR_H
#define TESTTABBAR_H

#include <QTabBar>
#include <QPainter>
#include <QStylePainter>
#include <QStyleOptionTab>

class TestTabBar : public QTabBar
{
    public:
        explicit TestTabBar(QWidget* parent=0) : QTabBar(parent)
        {
            //setIconSize(QSize(94,51));
        }

    protected:
        QSize tabSizeHint(int) const
        {
            return QSize(113,50);
        }




        void paintEvent(QPaintEvent *){
            QStylePainter p(this);


             for (int index = 0; index < count(); index++)
             {
                      QStyleOptionTabV3 tab;
                      initStyleOption(&tab, index);


                      QIcon tempIcon = tabIcon(index);
                      QString tempText = this->tabText(index);

                      QRect tabrect = tabRect(index);

                      tab.icon = QIcon();
                      tab.text = QString();

                      p.drawControl(QStyle::CE_TabBarTab, tab);
                      tabrect.adjust(0, 0, 0, 0);

                    //  p.setPen(Qt::black);
                    //  p.setFont(QFont("Arial", 7));

                      //p.drawText(tabrect, Qt::AlignBottom | Qt::AlignHCenter, tempText );
                      tempIcon.paint(&p, tabrect, Qt::AlignTop | Qt::AlignLeft);

                      this->setTabIcon(index, tempIcon );
                      this->setTabText( index, tempText);


              }
        }
};

class TestTabWidget : public QTabWidget
{
public:

    /**@brief TabWidget 에  연동하여 그리기  **/
    explicit TestTabWidget(QWidget *parent = 0) : QTabWidget(parent)
    {
        setTabBar(new TestTabBar());
    }
};



#endif // TESTTABBAR_H
