#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "screenflow.h"
#include "ordersummarywidget.h"
#include "screen.h"

#include <QMainWindow>

class Size;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    static const QPoint SUMMARY_WIDGET_LOCATION;

    explicit MainWindow(const Product &product, QWidget *parent = 0);
    ~MainWindow();

    bool Start();

private slots:

    void NextScreen();
    void PreviousScreen();
    void FlavorSelected(QString flavor);
    void QuantitySelected(int quantity);
    void SizeSelected(const Size &size);

private:

    Ui::MainWindow *ui;
    QList<Screen *> m_screenList;
    ScreenFlow m_screenFlow;

    const Product &m_product;
    OrderSummaryWidget m_summaryWidget;

    void InitializeOrderProgressWidget();
    bool InitializeScreens();
    Screen *ScreenFactory(Screen::ScreenType_e screenType);
};

#endif // MAINWINDOW_H
