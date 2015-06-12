#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "size.h"

#include "startupscreen.h"
#include "flavorscreen.h"
#include "quantityscreen.h"
#include "packagescreen.h"
#include "ordersummaryscreen.h"
#include "processingscreen.h"
#include "common.h"

#include <QDebug>

const QPoint MainWindow::SUMMARY_WIDGET_LOCATION = QPoint(0, 360);

/**
 * @brief MainWindow::MainWindow
 * @param product
 * @param parent
 */
MainWindow::MainWindow(const Product &product, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_product(product),
    m_summaryWidget(product.GetProductImage(), this)
{
    ui->setupUi(this);

    InitializeOrderProgressWidget();

    for (int i = Screen::eScreenType_Start; i < Screen::eScreenType_Max; i++) {

        Screen *screen = ScreenFactory(static_cast<Screen::ScreenType_e>(i));
        m_screenList.append(screen);
        m_screenFlow.RegisterScreen(screen);

        connect(screen, SIGNAL(FlavorSelection(QString)), this, SLOT(FlavorSelected(QString)));
        connect(screen, SIGNAL(QuantitySelected(int)), this, SLOT(QuantitySelected(int)));
        connect(screen, SIGNAL(SizeSelected(const Size &)), this, SLOT(SizeSelected(const Size &)));

    }

    connect(&m_screenFlow, SIGNAL(ScreenNext()), this, SLOT(NextScreen()));
    connect(&m_screenFlow, SIGNAL(ScreenPrevious()), this, SLOT(PreviousScreen()));
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Start()
{
    bool status = true;

    status = InitializeScreens();
    qDebug() << (status ? "Screens Initialized" : "Failed to initialize screens");

    if (status) {

        status = m_screenFlow.Start();
        qDebug() << (status ? "Screens started" : "Failed to start screens");
    }

    return status;
}

/**
 * @brief MainWindow::NextScreen
 */
void MainWindow::NextScreen()
{
    qDebug() << "NEXT";
}

/**
 * @brief MainWindow::PreviousScreen
 */
void MainWindow::PreviousScreen()
{
    qDebug() << "PREVIOUS";
}

/**
 * @brief MainWindow::FlavorSelected
 * @param flavor
 */
void MainWindow::FlavorSelected(QString flavor)
{
    m_summaryWidget.SetFlavorLabel(flavor);
    m_summaryWidget.ActivateFlavorSelection();
}

/**
 * @brief MainWindow::QuantitySelected
 * @param quantity
 */
void MainWindow::QuantitySelected(int quantity)
{
    m_summaryWidget.SetQuantityLabel("Quantity " + QString::number(quantity));
    m_summaryWidget.ActivateQuantitySelection();
}

/**
 * @brief MainWindow::SizeSelected
 * @param size
 */
void MainWindow::SizeSelected(const Size &size)
{
    m_summaryWidget.SetSizeLabel(size.GetName());
    m_summaryWidget.ActivateSizeSelection();
}

/**
 * @brief MainWindow::InitializeOrderProgressWidget
 */
void MainWindow::InitializeOrderProgressWidget()
{
    // Initialize the order summary widget

    m_summaryWidget.SetFlavorLabel("Flavor");
    m_summaryWidget.SetQuantityLabel("Quantity");
    m_summaryWidget.SetSizeLabel("Size");
    m_summaryWidget.SetCrispLabel("Crispness");
    m_summaryWidget.SetPackageLabel("Package");

    m_summaryWidget.move(SUMMARY_WIDGET_LOCATION);
    m_summaryWidget.raise();

    m_summaryWidget.Reset();
}

/**
 * @brief MainWindow::InitializeScreens
 */
bool MainWindow::InitializeScreens()
{
    // Initialize and register the screens
    foreach (Screen *screen, m_screenList)
    {
        if (!screen->Init()) {

            qDebug() << "Failed to initialize: " << screen->GetScreenName();
            return false;
        }
    }

    return true;
}

Screen *MainWindow::ScreenFactory(Screen::ScreenType_e screenType)
{
    switch (screenType)
    {
        case Screen::eScreenType_Start:
            return new StartupScreen(m_product, this);
        case Screen::eScreenType_Flavor:
            return new FlavorScreen(m_product, this);
        case Screen::eScreenType_Quantity_Size:
            return new QuantityScreen(m_product, this);
        case Screen::eScreenType_Package_Crisp:
            return new PackageScreen(m_product, this);
        case Screen::eScreenType_OrderSummary:
            return new OrderSummaryScreen(m_product, this);
        case Screen::eScreenType_Processing:
            return new ProcessingScreen(m_product, this);
        default:
            return 0;
    }
}
