#include "flavorscreen.h"
#include "ui_flavorscreen.h"
#include "flavor.h"
#include "common.h"

#include <QSignalMapper>
#include <QHBoxLayout>
#include <QPainter>

/**
 * @brief FlavorScreen::FlavorScreen
 * @param product
 * @param parent
 * @param screenName
 */
FlavorScreen::FlavorScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(Screen::eScreenType_Flavor, product, parent, screenName),
    ui(new Ui::FlavorScreen),
    m_flavorSelectionIndex(0),
    m_optionSelectionIndex(0),
    m_flavorSelected(false),
    m_optionSelected(false)
{
    ui->setupUi(this);

    ui->FlavorScrollArea->setLayout(&m_flavorLayout);         // Set layout for flavor scroll area
    ui->AdditionalOptionScrollArea->setLayout(&m_optionsLayout);  // Set layout for additional options scroll
    m_flavors = m_product.GetProductFlavors();  // Get list of product flavors

    InitializeFlavors();

    connect(&m_flavorMapper, SIGNAL(mapped(int)), this, SLOT(FlavorSelected(int)));
    connect(ui->NextButton, SIGNAL(released()), this, SLOT(NextButtonReleased()));

    UpdateNextButtonState(); // Updated the Next button state
}

/**
 * @brief FlavorScreen::~FlavorScreen
 */
FlavorScreen::~FlavorScreen()
{
    delete ui;
}

/**
 * @brief FlavorScreen::Init
 * @return
 */
bool FlavorScreen::Init()
{
    hide();
    return true;
}

/**
 * @brief FlavorScreen::Reset
 */
void FlavorScreen::Reset()
{

}

/**
 * @brief FlavorScreen::BackButtonReleased
 */
void FlavorScreen::BackButtonReleased()
{
    emit Back();
}

/**
 * @brief FlavorScreen::NextButtonReleased
 */
void FlavorScreen::NextButtonReleased()
{
    emit Next();
}

/**
 * @brief FlavorScreen::FlavorSelected
 * @param flavorIndex
 */
void FlavorScreen::FlavorSelected(int flavorIndex)
{
    if (m_flavorWidgetList.at(flavorIndex)->GetCheckedState()) // Flavor selected
    {
        if(m_flavorSelected) // Previously selected flavor
        {
            m_flavorWidgetList.at(m_flavorSelectionIndex)->SetOptionBoxState(false); // Reset the previously selected option box
        }

        m_flavorSelectionIndex = flavorIndex; // Save the selection index
        m_flavorSelected = true;

        ClearFlavorOptions();

        if (m_flavors.at(flavorIndex)->GetFlavorOptions().isEmpty()) // check if there are an flavor options available
        {
            emit FlavorSelection(m_flavors.at(flavorIndex)->GetFlavorName());
        }

        ShowFlavorOptions();


    }
    else // Option unchecked.
    {
        m_flavorSelected = false;   // Reset the flag
        ClearFlavorOptions();
    }
}

/**
 * @brief FlavorScreen::FlavorOptionSelected
 * @param optionIndex
 */
void FlavorScreen::FlavorOptionSelected(int optionIndex)
{
    if (m_optionWidgetList.at(optionIndex)->GetCheckedState())
    {
        if(m_optionSelected)
        {
            m_optionWidgetList.at(m_optionSelectionIndex)->SetOptionBoxState(false); // Reset the previously selected option box
        }

        m_optionSelectionIndex = optionIndex; // Save the selection index
        m_optionSelected = true;

        // Update the order
    }
    else // Option unchecked.
    {
        m_optionSelected = false;   // Reset the flag
    }

    UpdateNextButtonState();

    emit FlavorSelection(m_optionWidgetList.at(optionIndex)->GetOptionBoxLabel());
}

/**
 * @brief FlavorScreen::paintEvent
 */
void FlavorScreen::paintEvent(QPaintEvent *)
{
    GuiCommon::PaintSeparator(this, QPoint(10, 35), QPoint(630, 35));
    GuiCommon::PaintSeparator(this, QPoint(10, 205), QPoint(630, 205));
}

/**
 * @brief FlavorScreen::InitializeFlavors
 */
void FlavorScreen::InitializeFlavors()
{
    int flavorIndex = 0;

    // Create a list of all the flavors options that are available for this product group.
    // Create an individual box container for each of the flavors.
    foreach (const Flavor *flavor, m_flavors)
    {
        OptionBoxWidget *optionBox = new OptionBoxWidget(); // Create a new custom option box widget
        optionBox->SetOptionBoxImage(flavor->GetFlavorImageUrl());  // Set flavor image
        optionBox->SetOptionBoxLabel(flavor->GetFlavorName());  // Set flavor name

        ui->FlavorScrollArea->layout()->addWidget(optionBox);   // Add the widget to the scroll area

        connect(optionBox, SIGNAL(OptionSelected()), &m_flavorMapper, SLOT(map()));
        m_flavorMapper.setMapping(optionBox, flavorIndex); // Create the mapping to the index

        m_flavorWidgetList.insert(flavorIndex, optionBox);    // Add to the list at index value
        flavorIndex++;
    }

}

/**
 * @brief FlavorScreen::UpdateNextButtonState
 *
 * Displays the next button if a valid option
 * has been selected
 *
 */
void FlavorScreen::UpdateNextButtonState()
{
    m_optionSelected ? ui->NextButton->show() : ui->NextButton->hide();
    //ui->NextButton->setEnabled(m_flavorSelected);
}

/**
 * @brief FlavorScreen::ShowFlavorOptions
 *
 * Displays the options for each of the flavors
 *
 *
 */
void FlavorScreen::ShowFlavorOptions()
{
    QList<const FlavorProperties *> flavorOptions = m_flavors.at(m_flavorSelectionIndex)->GetFlavorOptions();

    m_optionMapper = QSharedPointer<QSignalMapper>(new QSignalMapper(this));
    int optionIndex = 0;

    foreach (const FlavorProperties *option, flavorOptions)
    {
        OptionBoxWidget *optionBox = new OptionBoxWidget;

        optionBox->SetOptionBoxImage(option->GetOptionImageUrl());
        optionBox->SetOptionBoxLabel(option->GetOptionName());

        ui->AdditionalOptionScrollArea->layout()->addWidget(optionBox);

        connect(optionBox, SIGNAL(OptionSelected()), m_optionMapper.data(), SLOT(map()));
        m_optionMapper->setMapping(optionBox, optionIndex); // Create the mapping to the index

        m_optionWidgetList.insert(optionIndex, optionBox);    // Add to the list at index value
        optionIndex++;
    }


    if (!optionIndex)   // If there are no options set the option selected flag to true
        m_optionSelected = true;

    connect(m_optionMapper.data(), SIGNAL(mapped(int)), this, SLOT(FlavorOptionSelected(int)));

    UpdateNextButtonState(); // Update the button state
}

/**
 * @brief FlavorScreen::ClearFlavorOptions
 */
void FlavorScreen::ClearFlavorOptions()
{
    QLayoutItem *item;

    // Remove all the widgets from the scroll area
    while ((item = ui->AdditionalOptionScrollArea->layout()->takeAt(0)) != 0)
    {
        delete item->widget();
        delete item;
    }

    m_optionSelected = false;
    m_optionSelectionIndex = 0;
}
