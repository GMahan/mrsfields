#ifndef OPTIONBOXWIDGET_H
#define OPTIONBOXWIDGET_H

#include <QPushButton>
#include <QString>
#include <QColor>
#include <QLabel>
#include <QFont>
#include <QStaticText>

namespace Ui {
class OptionBoxWidget;
}

class OptionBoxWidget : public QPushButton
{
    Q_OBJECT

    public:
        explicit OptionBoxWidget(QWidget *parent = 0);
        ~OptionBoxWidget();

        QString GetOptionBoxLabel() const;
        void SetOptionBoxLabel(const QString &label);
        void SetOptionBoxImage(const QString &imageUrl);
        void SetOptionBoxState(bool state);
        void SetLabelFont(const QFont &font);
        void SetSelectionColor(const QColor &color);
        void SetSelectionColor(Qt::GlobalColor color);
        void SetUnselectedColor(const QColor &color);
        void SetUnselectedColor(Qt::GlobalColor color);

        bool GetCheckedState() const;

    protected:

        void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    signals:

        void OptionSelected();

    private slots:

        void Checked();

    private:

        bool m_selected;
        QString m_label;
        QString m_imageUrl;
        QColor m_selectedColor;
        QColor m_unselectedColor;
        QFont m_font;
        //Ui::OptionBoxWidget *ui;

        void UpdateOptionBoxImage();
};

#endif // OPTIONBOXWIDGET_H
