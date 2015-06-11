/********************************************************************************
** Form generated from reading UI file 'optionboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONBOXWIDGET_H
#define UI_OPTIONBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionBoxWidget
{
public:
    QLabel *NameLabel;
    QLabel *BoxImageLabel;
    QPushButton *Button;
    QLabel *ImageLabel;

    void setupUi(QWidget *OptionBoxWidget)
    {
        if (OptionBoxWidget->objectName().isEmpty())
            OptionBoxWidget->setObjectName(QStringLiteral("OptionBoxWidget"));
        OptionBoxWidget->resize(100, 100);
        OptionBoxWidget->setMaximumSize(QSize(16777215, 16777215));
        OptionBoxWidget->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        NameLabel = new QLabel(OptionBoxWidget);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));
        NameLabel->setGeometry(QRect(0, 77, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("Chalkboard"));
        NameLabel->setFont(font);
        NameLabel->setStyleSheet(QLatin1String("background-color:none;\n"
"color:rgb(255,255,255)"));
        NameLabel->setAlignment(Qt::AlignCenter);
        BoxImageLabel = new QLabel(OptionBoxWidget);
        BoxImageLabel->setObjectName(QStringLiteral("BoxImageLabel"));
        BoxImageLabel->setGeometry(QRect(0, 0, 100, 100));
        BoxImageLabel->setStyleSheet(QStringLiteral("background-color:transparent;"));
        Button = new QPushButton(OptionBoxWidget);
        Button->setObjectName(QStringLiteral("Button"));
        Button->setGeometry(QRect(0, 0, 100, 100));
        Button->setStyleSheet(QStringLiteral("background-color: transparent;"));
        Button->setCheckable(false);
        Button->setChecked(false);
        Button->setAutoRepeat(false);
        Button->setFlat(true);
        ImageLabel = new QLabel(OptionBoxWidget);
        ImageLabel->setObjectName(QStringLiteral("ImageLabel"));
        ImageLabel->setGeometry(QRect(4, 4, 90, 60));
        BoxImageLabel->raise();
        ImageLabel->raise();
        NameLabel->raise();
        Button->raise();

        retranslateUi(OptionBoxWidget);

        QMetaObject::connectSlotsByName(OptionBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *OptionBoxWidget)
    {
        OptionBoxWidget->setWindowTitle(QApplication::translate("OptionBoxWidget", "Form", 0));
        NameLabel->setText(QApplication::translate("OptionBoxWidget", "Label", 0));
        BoxImageLabel->setText(QString());
        Button->setText(QString());
        ImageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OptionBoxWidget: public Ui_OptionBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONBOXWIDGET_H
