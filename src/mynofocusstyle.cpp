#include "mynofocusstyle.h"
#include <QDebug>

MyNoFocusStyle::MyNoFocusStyle()
{

}

MyNoFocusStyle::~MyNoFocusStyle()
{

}


void MyNoFocusStyle::drawPrimitive(
        PrimitiveElement element,
        const QStyleOption *option,
        QPainter *painter,
        const QWidget *widget) const
{
    if ( element == PE_FrameFocusRect ) return;
    QProxyStyle::drawPrimitive( element, option, painter, widget );
}
