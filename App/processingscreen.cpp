#include "processingscreen.h"
#include "ui_processingscreen.h"
#include "common.h"
#include <QTimer>
#include <QRectF>
#include <QPainter>
#include <QColor>
#include <QBrush>

/**
 * @brief ProcessingScreen::ProcessingScreen
 * @param product
 * @param parent
 * @param screenName
 */
ProcessingScreen::ProcessingScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(eScreenType_Processing, product, parent, screenName),
    ui(new Ui::ProcessingScreen),
    m_secondCount(0)
{
    ui->setupUi(this);

    UpdateFontProperties();

    m_processingTimer = new QTimer(this);

    connect(m_processingTimer, SIGNAL(timeout()), this, SLOT(UpdateRemainingTime()));
}

/**
 * @brief ProcessingScreen::~ProcessingScreen
 */
ProcessingScreen::~ProcessingScreen()
{
    delete ui;
}

/**
 * @brief ProcessingScreen::Init
 * @return
 */
bool ProcessingScreen::Init()
{
    hide();
    return true;
}

/**
 * @brief ProcessingScreen::Reset
 */
void ProcessingScreen::ResetScreen()
{

}

/**
 * @brief ProcessingScreen::showEvent
 */
void ProcessingScreen::showEvent(QShowEvent *)
{
    m_processingTimer->start(1000);
    m_secondCount = 0;
    UpdateTimeRemainingString();
}

void ProcessingScreen::paintEvent(QPaintEvent *)
{
    QRectF rectangle(230, 180, 200, 200);

    int startAngle = 90 * 16;
    int spanAngle = (360 - (m_secondCount * 360 / PROCESSING_TIME )) * 16;

    QColor color(255,0,0,50);
    QBrush brush(color);

    QPainter painter(this);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    painter.drawPie(rectangle, startAngle, spanAngle);
}

/**
 * @brief ProcessingScreen::UpdateRemainingTime
 */
void ProcessingScreen::UpdateRemainingTime()
{
    m_secondCount++;
    update();

    if (m_secondCount == PROCESSING_TIME) {

        m_processingTimer->stop();
        QTimer::singleShot(2000, this, SLOT(Done()));
    }

    UpdateTimeRemainingString();
}

/**
 * @brief ProcessingScreen::Done
 */
void ProcessingScreen::Done()
{
    emit Reset();
}

/**
 * @brief ProcessingScreen::UpdateFontProperties
 */
void ProcessingScreen::UpdateFontProperties()
{
    ui->ThankYouLabel->setFont(GuiCommon::GetUILabelFont());
    ui->ThankYouLabel->setStyleSheet(GuiCommon::GetUILableStyleSheet());
    ui->ThankYouLabel->setAlignment(Qt::AlignCenter);

    QFont font = GuiCommon::GetUILabelFont();
    font.setPixelSize(20);

    ui->TimeRemainingLabel->setFont(font);
    ui->TimeRemainingLabel->setStyleSheet(GuiCommon::GetUILableStyleSheet());
    ui->TimeRemainingLabel->setAlignment(Qt::AlignHCenter);
}

void ProcessingScreen::UpdateTimeRemainingString()
{
    if (m_secondCount == PROCESSING_TIME) {

        ui->TimeRemainingLabel->setText("Cookies are ready!!");
    }
    else {

        ui->TimeRemainingLabel->setText(QString("Enjoy your freshly baked cookie in %1 seconds")
                                        .arg(QString::number(PROCESSING_TIME - m_secondCount)));
    }
}
