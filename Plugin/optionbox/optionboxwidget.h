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

        static const int ICON_WIDTH = 60;
        static const int ICON_HEIGHT = 60;
        static const int BG_X_OFFSET = 5;
        static const int BG_Y_OFFSET = 5;
        static const int BG_WIDTH = 90;
        static const int BG_HEIGHT = 70;
        static const int TEXT_Y_OFFSET = 75;

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
        bool m_imageUpdated;
        bool m_labelUpdated;
        QString m_label;
        QImage m_image;
        QColor m_selectedColor;
        QColor m_unselectedColor;
        QFont m_font;
        QSize m_iconSize;

        //Ui::OptionBoxWidget *ui;

        void UpdateOptionBoxImage();
};

#endif // OPTIONBOXWIDGET_H
