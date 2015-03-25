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
         QSize tabSizeHint(int index) const
        {
            QSize m_size;

            if( index==0)
             m_size = QSize(94,50);
            else if(index==1)
             m_size = QSize(113,50);
            else if(index==2)
             m_size = QSize(113,50);
            else if(index ==3)
             m_size = QSize(115,50);
            else if(index==4)
             m_size = QSize(129,50);
            else if(index ==5)
             m_size = QSize(113,50);



            return m_size;

         }




        void paintEvent(QPaintEvent *)
        {

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

                      /**
                       * @brief Push Tab : Change Icon Image
                       *
                       */


                      this->setIconSize(QSize(tabrect.width(),tabrect.height()));
                      tempIcon.paint(&p, tabrect, Qt::AlignTop | Qt::AlignLeft);


                      this->setTabIcon(index, tempIcon );
                      this->setTabText( index, tempText);


              }
        }


};

        //  p.setPen(Qt::black);
        //  p.setFont(QFont("Arial", 7));
        //p.drawText(tabrect, Qt::AlignBottom | Qt::AlignHCenter, tempText );


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
