#include "ordersummaryscreen.h"
#include "ui_ordersummaryscreen.h"

OrderSummaryScreen::OrderSummaryScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(eScreenType_OrderSummary, product, parent, screenName),
    ui(new Ui::OrderSummaryScreen)
{
    ui->setupUi(this);
}

OrderSummaryScreen::~OrderSummaryScreen()
{
    delete ui;
}

bool OrderSummaryScreen::Init()
{
    hide();
    return true;
}

void OrderSummaryScreen::Reset()
{
;
}
