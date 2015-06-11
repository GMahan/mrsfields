#include "packagescreen.h"
#include "ui_packagescreen.h"
#include "common.h"

/**
 * @brief packagescreen::packagescreen
 * @param product
 * @param parent
 * @param screenName
 */
PackageScreen::PackageScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(eScreenType_Package_Crisp, product, parent, screenName),
    ui(new Ui::packagescreen)
{
    ui->setupUi(this);

    connect(ui->NextButton, SIGNAL(pressed()), this, SLOT(NextButtonReleased()));
    connect(ui->BackButton, SIGNAL(pressed()), this, SLOT(BackButtonReleased()));
}

/**
 * @brief packagescreen::~packagescreen
 */
PackageScreen::~PackageScreen()
{
    delete ui;
}

/**
 * @brief packagescreen::Init
 * @return
 */
bool PackageScreen::Init()
{
    hide();
    return true;
}

/**
 * @brief packagescreen::Reset
 */
void PackageScreen::Reset()
{

}

/**
 * @brief packagescreen::NextButtonReleased
 */
void PackageScreen::NextButtonReleased()
{
    emit Next();
}

/**
 * @brief packagescreen::BackButtonReleased
 */
void PackageScreen::BackButtonReleased()
{
    emit Back();
}

/**
 * @brief packagescreen::CrispnessChanged
 */
void PackageScreen::CrispnessChanged()
{

}

/**
 * @brief packagescreen::PackageSelected
 */
void PackageScreen::PackageSelection()
{

}

/**
 * @brief packagescreen::paintEvent
 */
void PackageScreen::paintEvent(QPaintEvent *)
{
    GuiCommon::PaintSeparator(this, QPoint(10, 35), QPoint(630, 35));
    GuiCommon::PaintSeparator(this, QPoint(10, 205), QPoint(630, 205));
}
