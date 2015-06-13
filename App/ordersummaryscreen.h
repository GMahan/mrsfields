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
    void ResetScreen();

private slots:

    void BackButtonReleased();
    void NextButtonReleased();

protected:

        void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    Ui::OrderSummaryScreen *ui;

    void SetFontProperties();
};

#endif // ORDERSUMMARYSCREEN_H
