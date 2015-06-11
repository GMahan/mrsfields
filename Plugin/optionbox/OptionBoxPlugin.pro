#-------------------------------------------------
#
# Project created by QtCreator 2015-02-15T18:40:16
#
#-------------------------------------------------

QT       += widgets designer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG      += plugin
CONFIG      += debug_and_release
TEMPLATE    = lib
#TEMPLATE     = app

TARGET = $$qtLibraryTarget($$TARGET)

target.path = /Users/MahanMacBook/qtprojects/plugins
INSTALLS += target

SOURCES +=\
    optionboxwidgetplugin.cpp \
    optionboxwidget.cpp

HEADERS  += \
    optionboxwidgetplugin.h \
    optionboxwidget.h

FORMS    += \
    optionboxwidget.ui

RESOURCES += \
    images.qrc
