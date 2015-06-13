#include "mainwindow.h"
#include "product.h"
#include "common.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the UI Font
    QGuiApplication::setFont(GuiCommon::GetUILabelFont());

    // Instantitate the cookie product
    Product *cookie = new Cookie;

    // Instantiate the main window screen
    MainWindow w(*cookie);

    if (w.Start()) {

        w.show();
        return a.exec();
    }
    else {

        qDebug() << "Unable to start UI";
        qApp->quit();
    }

    delete cookie;
}
