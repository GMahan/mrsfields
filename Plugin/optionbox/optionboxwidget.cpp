#include "optionboxwidget.h"
#include "ui_optionboxwidget.h"

const QString OptionBoxWidget::BOX_CHEKCED = "image: url(:/OptionBox/Images/OptionBoxSelected.png);";
const QString OptionBoxWidget::BOX_UNCHECKED = "image: url(:/OptionBox/Images/OptionBoxUnselected.png);";


OptionBoxWidget::OptionBoxWidget(QWidget *parent) :
    QWidget(parent),
    m_Selected(false),
    ui(new Ui::OptionBoxWidget)
{
    ui->setupUi(this);
    ui->BoxImageLabel->setStyleSheet(BOX_UNCHECKED);
    connect(ui->Button, SIGNAL(pressed()), this, SLOT(Checked()));
}

OptionBoxWidget::~OptionBoxWidget()
{
    delete ui;
}

QString OptionBoxWidget::GetOptionBoxLabel() const
{
    return ui->NameLabel->text();
}

void OptionBoxWidget::SetOptionBoxLabel(const QString &label)
{
    ui->NameLabel->setText(label);
}

void OptionBoxWidget::SetOptionBoxImage(const QString &imageUrl)
{
    QString imageString = QString("image: url(%1);").arg(imageUrl);
    ui->ImageLabel->setStyleSheet(imageString);
}

void OptionBoxWidget::SetOptionBoxState(bool state)
{
    m_Selected = state;
    UpdateOptionBoxImage();
}

bool OptionBoxWidget::GetCheckedState() const
{
    return m_Selected;
}

void OptionBoxWidget::Checked()
{
    m_Selected = !m_Selected;
    UpdateOptionBoxImage();
    emit OptionSelected();
}

void OptionBoxWidget::UpdateOptionBoxImage()
{
    ui->BoxImageLabel->setStyleSheet(m_Selected ? BOX_CHEKCED : BOX_UNCHECKED );
}


