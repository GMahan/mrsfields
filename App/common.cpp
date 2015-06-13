#include <QPainter>

#include "common.h"

/**
 * @brief GuiCommon::PaintSeparator
 * @param widget
 * @param start
 * @param end
 */
void GuiCommon::PaintSeparator(QWidget *widget, QPoint start, QPoint end)
{
    if (start != end) {

        QPainter painter(widget);
        QPen pen(Qt::darkRed, 1, Qt::SolidLine);
        painter.setPen(pen);
        painter.drawLine(start, end);
    }
}

/**
 * @brief GuiCommon::GetUILabelFont
 * @return
 */
QFont GuiCommon::GetUILabelFont()
{
    return QFont("Chalkboard", 16);
}

/**
 * @brief GuiCommon::GetUILableStyleSheet
 * @return
 */
QString GuiCommon::GetUILableStyleSheet()
{
    return QString("background-color:rgb(255, 255, 255); color:rgb(78, 78, 78);");
}
