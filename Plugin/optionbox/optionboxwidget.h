#ifndef OPTIONBOXWIDGET_H
#define OPTIONBOXWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class OptionBoxWidget;
}

class OptionBoxWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit OptionBoxWidget(QWidget *parent = 0);
        ~OptionBoxWidget();

        QString GetOptionBoxLabel() const;
        void SetOptionBoxLabel(const QString &label);
        void SetOptionBoxImage(const QString &imageUrl);
        void SetOptionBoxState(bool state);
        bool GetCheckedState() const;

    signals:

        void OptionSelected();

    private slots:

        void Checked();

    private:

        static const QString BOX_CHEKCED;
        static const QString BOX_UNCHECKED;
        bool m_Selected;
        Ui::OptionBoxWidget *ui;

        void UpdateOptionBoxImage();
};

#endif // OPTIONBOXWIDGET_H
