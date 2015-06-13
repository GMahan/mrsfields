#include "ordersummaryscreen.h"
#include "ui_ordersummaryscreen.h"
#include "common.h"

/**
 * @brief OrderSummaryScreen::OrderSummaryScreen
 * @param product
 * @param parent
 * @param screenName
 */
OrderSummaryScreen::OrderSummaryScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(eScreenType_OrderSummary, product, parent, screenName),
    ui(new Ui::OrderSummaryScreen)
{
    ui->setupUi(this);

    SetFontProperties();

    connect(ui->BackButton, SIGNAL(released()), this, SLOT(BackButtonReleased()));
    connect(ui->NextButton, SIGNAL(released()), this, SLOT(NextButtonReleased()));
}

/**
 * @brief OrderSummaryScreen::~OrderSummaryScreen
 */
OrderSummaryScreen::~OrderSummaryScreen()
{
    delete ui;
}

/**
 * @brief OrderSummaryScreen::Init
 * @return
 */
bool OrderSummaryScreen::Init()
{
    hide();
    return true;
}

/**
 * @brief OrderSummaryScreen::Reset
 */
void OrderSummaryScreen::ResetScreen()
{

}

/**
 * @brief OrderSummaryScreen::BackButtonReleased
 */
void OrderSummaryScreen::BackButtonReleased()
{
    emit Back();
}

/**
 * @brief OrderSummaryScreen::NextButtonReleased
 *
 * Emits the next signal to transition to the next screen
 */
void OrderSummaryScreen::NextButtonReleased()
{
    emit Next();
}

/**
 * @brief OrderSummaryScreen::paintEvent
 *
 * Paints line seperators on the widget
 *
 */
void OrderSummaryScreen::paintEvent(QPaintEvent *)
{
    GuiCommon::PaintSeparator(this, QPoint(10, 35), QPoint(630, 35));
    GuiCommon::PaintSeparator(this, QPoint(10, 100), QPoint(630, 100));
}

/**
 * @brief OrderSummaryScreen::SetFontProperties
 *
 * Sets the font properties for the lables
 */
void OrderSummaryScreen::SetFontProperties()
{
    ui->OrderSummaryLabel->setFont(GuiCommon::GetUILabelFont());
    ui->OrderSummaryLabel->setStyleSheet(GuiCommon::GetUILableStyleSheet());

    ui->NextButton->setFont(GuiCommon::GetUILabelFont());
}


