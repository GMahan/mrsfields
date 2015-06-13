#include "quantityscreen.h"
#include "ui_quantityscreen.h"
#include "screen.h"
#include "optionboxwidget.h"
#include "common.h"

const QString QuantityScreen::LABEL_DEFAULT = "background-color:rgb(255, 255, 255);"
                                               "color:rgb(200, 200, 200)";

const QString QuantityScreen::LABEL_HIGHLIGHT = "background-color:rgb(255, 255, 255);"
                                                "color:rgb(50, 50, 50)";

/**
 * @brief QuantityScreen::QuantityScreen
 * @param product
 * @param parent
 * @param screenName
 */
QuantityScreen::QuantityScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(eScreenType_Quantity_Size, product, parent, screenName),
    ui(new Ui::QuantityScreen)
{
    ui->setupUi(this);

    ui->SizeScrollArea->setLayout(&m_sizeLayout);
    m_sizeList = m_product.GetProductSizes();   // Get the size list

    InitalizeSizeWidgets();
    CreateLabelList();  // Create the label list
    ResetQuantityLabels();  // Reset labels

    connect(ui->NextButton, SIGNAL(pressed()), this, SLOT(NextButtonReleased()));
    connect(ui->BackButton, SIGNAL(pressed()), this, SLOT(BackButtonReleased()));
    connect(ui->QuantitySlider, SIGNAL(sliderReleased()), this, SLOT(QuantityChanged()));
}

/**
 * @brief QuantityScreen::~QuantityScreen
 */
QuantityScreen::~QuantityScreen()
{
    delete ui;
}

/**
 * @brief QuantityScreen::Init
 * @return
 */
bool QuantityScreen::Init()
{
    hide();
    return true;
}

/**
 * @brief QuantityScreen::Reset
 */
void QuantityScreen::ResetScreen()
{

}

/**
 * @brief QuantityScreen::NextButtonReleased
 */
void QuantityScreen::NextButtonReleased()
{
    emit Next();
}

/**
 * @brief QuantityScreen::BackButtonReleased
 */
void QuantityScreen::BackButtonReleased()
{
    emit Back();
}

/**
 * @brief QuantityScreen::QuantityChanged
 */
void QuantityScreen::QuantityChanged()
{
   int quantity = ui->QuantitySlider->sliderPosition();

   ResetQuantityLabels();
   m_quantityLabels.at(quantity)->setStyleSheet(LABEL_HIGHLIGHT);

   emit QuantitySelected(quantity);
}

/**
 * @brief QuantityScreen::SizeSelection
 * @param index
 */
void QuantityScreen::SizeSelection(int index)
{
    // Clear all selections
    foreach(OptionBoxWidget *option, m_sizeOptionWidgetList)
    {
        option->SetOptionBoxState(false);
    }

    m_sizeOptionWidgetList.at(index)->SetOptionBoxState(true);

    emit SizeSelected(*m_sizeList.at(index));

    QuantityChanged();  // Update the order quantity, as it could still be at default.
}

/**
 * @brief QuantityScreen::InitalizeSizeWidgets
 */
void QuantityScreen::InitalizeSizeWidgets()
{
    int index = 0;

    foreach (const Size *size, m_sizeList)
    {
        // Set up the option box widget
        OptionBoxWidget *sizeOption = new OptionBoxWidget(this);
        sizeOption->setObjectName(size->GetName());
        sizeOption->SetOptionBoxImage(size->GetImageURL());
        sizeOption->SetOptionBoxLabel(size->GetName() + " - $" + QString::number(size->GetPrice(), 'f', 2));

        // Add option box to layout
        ui->SizeScrollArea->layout()->addWidget(sizeOption);

        connect(sizeOption, SIGNAL(OptionSelected()), &m_sizeMapper, SLOT(map()));
        m_sizeMapper.setMapping(sizeOption, index); // Create the mapping to the index

        m_sizeOptionWidgetList.append(sizeOption);
        index++;
    }

    connect(&m_sizeMapper, SIGNAL(mapped(int)), this, SLOT(SizeSelection(int)));
}

/**
 * @brief QuantityScreen::CreateLabelList
 */
void QuantityScreen::CreateLabelList()
{
    m_quantityLabels.insert(0, ui->L1_1);   // Dummy insert
    m_quantityLabels.insert(1, ui->L1_1);
    m_quantityLabels.insert(2, ui->L1_2);
    m_quantityLabels.insert(3, ui->L1_3);
    m_quantityLabels.insert(4, ui->L1_4);
    m_quantityLabels.insert(5, ui->L1_5);
    m_quantityLabels.insert(6, ui->L1_6);
    m_quantityLabels.insert(7, ui->L1_7);
    m_quantityLabels.insert(8, ui->L1_8);
    m_quantityLabels.insert(9, ui->L1_9);
    m_quantityLabels.insert(10, ui->L1_10);
    m_quantityLabels.insert(11, ui->L1_11);
    m_quantityLabels.insert(12, ui->L1_12);
}

/**
 * @brief QuantityScreen::ResetQuantityLabels
 */
void QuantityScreen::ResetQuantityLabels()
{
    foreach (QLabel *label, m_quantityLabels)
    {
        label->setStyleSheet(LABEL_DEFAULT);
    }
}

/**
 * @brief QuantityScreen::paintEvent
 */
void QuantityScreen::paintEvent(QPaintEvent *)
{
    GuiCommon::PaintSeparator(this, QPoint(10, 35), QPoint(630, 35));
    GuiCommon::PaintSeparator(this, QPoint(10, 205), QPoint(630, 205));
}


