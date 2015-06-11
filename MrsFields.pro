#-------------------------------------------------
#
# Project created by QtCreator 2015-02-14T07:48:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MrsFields
TEMPLATE = app

macx: LIBS += -L$$PWD/../../Plugins/OptionBoxPlugin/ -lOptionBoxPlugin

INCLUDEPATH += $$PWD/../../Plugins/OptionBoxPlugin
DEPENDPATH += $$PWD/../../Plugins/OptionBoxPlugin

SOURCES += main.cpp\
        mainwindow.cpp \
    startupscreen.cpp \
    screen.cpp \
    screenflow.cpp \
    flavorscreen.cpp \
    order.cpp \
    product.cpp \
    flavor.cpp \
    quantityscreen.cpp \
    ordersummarywidget.cpp \
    size.cpp \
    common.cpp \
    packagescreen.cpp \
    package.cpp \
    ordersummaryscreen.cpp \
    processingscreen.cpp

HEADERS  += mainwindow.h \
    startupscreen.h \
    screen.h \
    screenflow.h \
    flavorscreen.h \
    order.h \
    product.h \
    flavor.h \
    quantityscreen.h \
    ordersummarywidget.h \
    size.h \
    common.h \
    packagescreen.h \
    package.h \
    ordersummaryscreen.h \
    processingscreen.h

FORMS    += mainwindow.ui \
    startupscreen.ui \
    flavorscreen.ui \
    quantityscreen.ui \
    ordersummarywidget.ui \
    packagescreen.ui \
    ordersummaryscreen.ui \
    processingscreen.ui

RESOURCES += \
    images.qrc


