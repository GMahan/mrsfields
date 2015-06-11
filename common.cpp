#include <QPainter>

#include "common.h"


void GuiCommon::PaintSeparator(QWidget *widget, QPoint start, QPoint end)
{
    if (start != end) {

        QPainter painter(widget);
        QPen pen(Qt::darkRed, 1, Qt::SolidLine);
        painter.setPen(pen);
        painter.drawLine(start, end);
    }
}
