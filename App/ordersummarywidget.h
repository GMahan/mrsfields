#ifndef ORDERSUMMARYWIDGET_H
#define ORDERSUMMARYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QList>
#include <QStringList>

namespace Ui {
class OrderSummaryWidget;
}

class OrderSummaryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderSummaryWidget(const QString &imageUrl, QWidget *parent = 0);
    ~OrderSummaryWidget();

    static const QString ACTIVE_FONT_COLOR;

    void SetFlavorLabel(QString flavor);
    void SetQuantityLabel(QString quantity);
    void SetSizeLabel(QString size);
    void SetCrispLabel(QString crisp);
    void SetPackageLabel(QString package);

    void ActivateFlavorSelection();
    void ActivateQuantitySelection();
    void ActivateSizeSelection();
    void ActivatePackageSelection();
    void ActivateCrispSelection();
    void Reset();

    void SetImageUrl(const QString &activeImageUrl);
    void SetActiveSelectionName(const QString &name);

protected:

    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:

    class Label{

    public:

        explicit Label(QLabel* nameLabel, QLabel* imageLabel, QLabel* maskLabel) :
            name(nameLabel),
            image(imageLabel),
            mask(maskLabel)
        {}
        ~Label() {}

        QLabel* name;
        QLabel* image;
        QLabel* mask;

    };

    Ui::OrderSummaryWidget *ui;
    QList<Label> m_labelList;
    quint8 m_currentIndex;
    QString m_imageUrl;

    void SetFontProperties();
    void InitializeLabelList();
    void SetDefaultLabelColors();
    void ChangeActiveLabel();

};

#endif // ORDERSUMMARYWIDGET_H
