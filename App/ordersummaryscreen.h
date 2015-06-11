#ifndef ORDERSUMMARYSCREEN_H
#define ORDERSUMMARYSCREEN_H

#include "screen.h"

#include <QWidget>

namespace Ui {
class OrderSummaryScreen;
}

class OrderSummaryScreen : public Screen
{
    Q_OBJECT

public:
    explicit OrderSummaryScreen(const Product &product, QWidget *parent = 0, const QString &screenName ="Summary Screen");
    ~OrderSummaryScreen();

    bool Init();
    void Reset();


private:
    Ui::OrderSummaryScreen *ui;
};

#endif // ORDERSUMMARYSCREEN_H
