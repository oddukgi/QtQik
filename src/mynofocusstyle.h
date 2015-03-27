#ifndef MYNOFOCUSSTYLE_H
#define MYNOFOCUSSTYLE_H

#include <QProxyStyle>

class MyNoFocusStyle : public QProxyStyle
{
    Q_OBJECT

    public:
      MyNoFocusStyle();
      ~MyNoFocusStyle();
      void drawPrimitive(
              PrimitiveElement element,
              const QStyleOption *option,
              QPainter *painter,
              const QWidget *widget) const;

};

#endif // MYNOFOCUSSTYLE_H
