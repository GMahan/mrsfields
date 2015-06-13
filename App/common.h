#ifndef COMMON_H
#define COMMON_H

#include <QPoint>
#include <QWidget>
#include <QFont>
#include <QString>
#include <QLabel>
#include <QPushButton>

namespace GuiCommon {

    QString GetUILableStyleSheet();
    QFont GetUILabelFont();

    void PaintSeparator(QWidget *widget, QPoint start, QPoint end);

}

#endif // COMMON_H

