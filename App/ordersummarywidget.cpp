#include "ordersummarywidget.h"
#include "ui_ordersummarywidget.h"
#include "common.h"

const QString OrderSummaryWidget::ACTIVE_FONT_COLOR = "color:rgb(50, 50, 50)";

/**
 * @brief OrderSummaryWidget::OrderSummaryWidget
 * @param imageUrl
 * @param parent
 */
OrderSummaryWidget::OrderSummaryWidget(const QString &imageUrl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderSummaryWidget),
    m_currentIndex(0),
    m_imageUrl(imageUrl)
{
    ui->setupUi(this);

    // Initialize the label list
    InitializeLabelList();
    // Set the default colors
    SetDefaultLabelColors();
    // Change the active label color
    ChangeActiveLabel();
}

/**
 * @brief OrderSummaryWidget::~OrderSummaryWidget
 */
OrderSummaryWidget::~OrderSummaryWidget()
{
    delete ui;
}

/**
 * @brief OrderSummaryWidget::SetFlavorLabel
 * @param flavor
 */
void OrderSummaryWidget::SetFlavorLabel(QString flavor)
{
    ui->FlavorLabel->setText(flavor);
}

/**
 * @brief OrderSummaryWidget::SetQuantityLabel
 * @param quantity
 */
void OrderSummaryWidget::SetQuantityLabel(QString quantity)
{
    ui->QuantityLabel->setText(quantity);
}

/**
 * @brief OrderSummaryWidget::SetSizeLabel
 * @param size
 */
void OrderSummaryWidget::SetSizeLabel(QString size)
{
    ui->SizeLabel->setText(size);
}

/**
 * @brief OrderSummaryWidget::SetCrispLabel
 * @param crisp
 */
void OrderSummaryWidget::SetCrispLabel(QString crisp)
{
    ui->Crispness->setText(crisp);
}

/**
 * @brief OrderSummaryWidget::SetPackageLabel
 * @param package
 */
void OrderSummaryWidget::SetPackageLabel(QString package)
{
    ui->PackageLabel->setText(package);
}

/**
 * @brief OrderSummaryWidget::ActivateFlavorSelection
 */
void OrderSummaryWidget::ActivateFlavorSelection()
{
    ui->FlavorLabel->setStyleSheet(ACTIVE_FONT_COLOR);
    ui->FlavorMask->lower();
}

/**
 * @brief OrderSummaryWidget::ActivateQuantitySelection
 */
void OrderSummaryWidget::ActivateQuantitySelection()
{
    ui->QuantityLabel->setStyleSheet(ACTIVE_FONT_COLOR);
    ui->QuantityMask->lower();
}

/**
 * @brief OrderSummaryWidget::ActivateSizeSelection
 */
void OrderSummaryWidget::ActivateSizeSelection()
{
    ui->SizeLabel->setStyleSheet(ACTIVE_FONT_COLOR);
    ui->SizeMask->lower();
}

/**
 * @brief OrderSummaryWidget::ActivatePackageSelection
 */
void OrderSummaryWidget::ActivatePackageSelection()
{
    ui->PackageLabel->setStyleSheet(ACTIVE_FONT_COLOR);
    ui->PackageMask->lower();
}

/**
 * @brief OrderSummaryWidget::ActivateCrispSelection
 */
void OrderSummaryWidget::ActivateCrispSelection()
{
    ui->Crispness->setStyleSheet(ACTIVE_FONT_COLOR);
    ui->Crispness->lower();
}

/**
 * @brief OrderSummaryWidget::SetImageUrl
 * @param activeImageUrl
 */
void OrderSummaryWidget::SetImageUrl(const QString &activeImageUrl)
{
    m_imageUrl = activeImageUrl;
}

/**
 * @brief OrderSummaryWidget::SetActiveSelectionName
 * @param name
 */
void OrderSummaryWidget::SetActiveSelectionName(const QString &name)
{
    m_labelList[m_currentIndex].name->setText(name);
}

/**
 * @brief OrderSummaryWidget::paintEvent
 */
void OrderSummaryWidget::paintEvent(QPaintEvent *)
{
    GuiCommon::PaintSeparator(this, QPoint(10, 28), QPoint(630, 28));
    GuiCommon::PaintSeparator(this, QPoint(10, 108), QPoint(630, 108));
}

/**
 * @brief OrderSummaryWidget::InitializeLabelList
 */
void OrderSummaryWidget::InitializeLabelList()
{
    m_labelList.insert(0, Label(ui->FlavorLabel,   ui->FlavorImage, ui->FlavorMask));
    m_labelList.insert(1, Label(ui->SizeLabel,     ui->SizeImage,   ui->SizeMask));
    m_labelList.insert(2, Label(ui->QuantityLabel, ui->QuantityImage, ui->QuantityMask));
    m_labelList.insert(3, Label(ui->Crispness,     ui->CrispImage, ui->CrispMask));
    m_labelList.insert(4, Label(ui->PackageLabel,  ui->PackageImage, ui->PackageMask));
}

/**
 * @brief OrderSummaryWidget::SetDefaultLabelColors
 */
void OrderSummaryWidget::SetDefaultLabelColors()
{
    QString bgColor = "background-color:none";
    QString fontColor = "color:rgb(150, 150, 150)";

    foreach (Label label, m_labelList)
    {
        label.name->setStyleSheet(fontColor);
    }
}

/**
 * @brief OrderSummaryWidget::Reset
 */
void OrderSummaryWidget::Reset()
{
    QString imageString = QString("image: url(%1);").arg(m_imageUrl);

    foreach (Label label, m_labelList)
    {
       label.image->setStyleSheet(imageString);
       label.mask->raise();
    }
}

/**
 * @brief OrderSummaryWidget::ChangeActiveLabel
 */
void OrderSummaryWidget::ChangeActiveLabel()
{
    QString bgColor = "background-color:none";

    // Reset all label colors
    SetDefaultLabelColors();
    // Reset all images
    Reset();

    // Set the color of the active label
    m_labelList[m_currentIndex].name->setStyleSheet(ACTIVE_FONT_COLOR);
    m_labelList[m_currentIndex].mask->lower();

    QString imageString = QString("image: url(%1);").arg(m_imageUrl);

    m_labelList[m_currentIndex].image->setStyleSheet(imageString);
}
