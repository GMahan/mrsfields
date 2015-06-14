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
    m_label(""),
    m_imageUrl(""),
    m_selectedColor(Qt::darkRed),
    m_unselectedColor(Qt::black)
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
}

void OptionBoxWidget::SetOptionBoxImage(const QString &imageUrl)
{
    m_imageUrl = imageUrl;
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
    int imageWidth = 60;
    int imageHeight = 60;
    int bgX = 5;
    int bgY = 5;
    int bgWidth = 90;
    int bgHeight = 70;
    int textY = 75;

    QSize imageSize(imageWidth, imageHeight);
    QPoint imageLocation((width() / 2) - (imageWidth / 2) , (bgY + bgHeight / 2) - (imageHeight / 2));

    QSize imageBgSize(bgWidth, bgHeight);
    QPoint imageBgLocation(bgX, bgY);

    QRectF imageRect(imageLocation, imageSize);
    QRectF sourceRect(QPoint(0,0), imageSize);

    QImage image(m_imageUrl);
    QImage scaledImage = image.scaled(imageSize, Qt::KeepAspectRatio);

    QBrush brush(m_selected ? m_selectedColor : m_unselectedColor);

    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);
    painter.setFont(m_font);

    painter.setBrush(brush);
    painter.drawRect(QRect(QPoint(0,0), size())); // Paint widget

    brush.setColor(Qt::white);
    painter.setBrush(brush);
    painter.drawRect(QRect(imageBgLocation, imageBgSize)); // Paint image background
    painter.drawImage(imageRect, scaledImage, sourceRect); // Paint image

    QPen pen;
    pen.setColor(QColor(Qt::white));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawText(QRect(QPoint(0, textY), QSize(width(), 20)),
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


