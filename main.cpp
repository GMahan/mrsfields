#include "mainwindow.h"
#include "product.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Cookie cookie;

    MainWindow w(cookie);

    if (w.Start()) {

        w.show();
        return a.exec();
    }
    else {

        qDebug() << "Unable to start UI";
        qApp->quit();
    }


}
