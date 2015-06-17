#include "optionboxwidget.h"
#include "ui_optionboxwidget.h"

#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QRgb>
#include <QRectF>
#include <QImage>

OptionBoxWidget::OptionBoxWidget(QWidget *parent) :
    QPushButton(parent),
    m_selected(false),
    m_imageUpdated(true),
    m_labelUpdated(true),
    m_label(""),
    m_image(),
    m_selectedColor(Qt::darkRed),
    m_unselectedColor(Qt::black),
    m_font(),
    m_iconSize(ICON_WIDTH, ICON_HEIGHT)
{
    setMaximumSize(QSize(100,100));

    connect(this, SIGNAL(pressed()), this, SLOT(Checked()));
}

OptionBoxWidget::~OptionBoxWidget()
{

}

QString OptionBoxWidget::GetOptionBoxLabel() const
{
    return m_label;
}

void OptionBoxWidget::SetOptionBoxLabel(const QString &label)
{
    m_label = label;
    m_labelUpdated = false;
    update();
}

void OptionBoxWidget::SetOptionBoxImage(const QString &imageUrl)
{
    m_image.load(imageUrl);
    m_imageUpdated = false;
    update();
}

void OptionBoxWidget::SetOptionBoxState(bool state)
{
    m_selected = state;
    update();
}

void OptionBoxWidget::SetLabelFont(const QFont &font)
{
    m_font = font;

    if (m_font.pointSize() > 12) {
        m_font.setPointSize(12);
    }

    m_labelUpdated = false;
    update();
}

void OptionBoxWidget::SetSelectionColor(const QColor &color)
{
    m_selectedColor = color;
}

void OptionBoxWidget::SetSelectionColor(Qt::GlobalColor color)
{
    m_selectedColor = color;
}

void OptionBoxWidget::SetUnselectedColor(const QColor &color)
{
    m_unselectedColor = color;
}

void OptionBoxWidget::SetUnselectedColor(Qt::GlobalColor color)
{
    m_unselectedColor = color;
}

bool OptionBoxWidget::GetCheckedState() const
{
    return m_selected;
}

void OptionBoxWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(m_selected ? m_selectedColor : m_unselectedColor));

    painter.drawRect(QRect(QPoint(0,0), size())); // Paint widget

    painter.setBrush(QBrush(Qt::white)); // paint image background color white

    QSize imageBgSize(BG_WIDTH, BG_HEIGHT);
    QPoint imageBgLocation(BG_X_OFFSET, BG_Y_OFFSET);

    painter.drawRect(QRect(imageBgLocation,
                           imageBgSize)); // Paint image background


    QPoint imageLocation((width() / 2) - (ICON_WIDTH / 2) ,
                         (BG_Y_OFFSET + BG_HEIGHT / 2) - (ICON_HEIGHT / 2));

    painter.drawImage(QRectF(imageLocation, m_iconSize),
                      QImage(m_image.scaled(m_iconSize, Qt::KeepAspectRatio)),
                      QRectF(QPoint(0,0), m_iconSize)); // Paint image



    QPen pen;
    pen.setColor(QColor(Qt::white));
    pen.setWidth(2);
    painter.setFont(m_font);
    painter.setPen(pen);
    painter.drawText(QRect(QPoint(0, TEXT_Y_OFFSET), QSize(width(), 20)),
                     Qt::AlignCenter,
                     m_label);
}

void OptionBoxWidget::Checked()
{
    m_selected = !m_selected;
    update();
    //UpdateOptionBoxImage();
    emit OptionSelected();
}

void OptionBoxWidget::UpdateOptionBoxImage()
{
    //ui->BoxImageLabel->setStyleSheet(m_Selected ? BOX_CHEKCED : BOX_UNCHECKED );
}


