#ifndef QUANTITYSCREEN_H
#define QUANTITYSCREEN_H

#include "screen.h"
#include "size.h"
#include "optionboxwidget.h"

#include <QWidget>
#include <QSharedPointer>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QString>

namespace Ui {
class QuantityScreen;
}

class QHBoxLayout;
class QLabel;

class QuantityScreen : public Screen
{
    Q_OBJECT

public:

    static const QString LABEL_DEFAULT;
    static const QString LABEL_HIGHLIGHT;

    explicit QuantityScreen(const Product &product, QWidget *parent = 0, const QString &screenName ="Quantity Screen");
    ~QuantityScreen();
    bool Init();
    void Reset();

signals:

    void QuantitySelected(int);
    void SizeSelected(const Size &);

private slots:
    void NextButtonReleased();
    void BackButtonReleased();
    void QuantityChanged();
    void SizeSelected(int index);

private:

    void InitalizeSizeWidgets();
    void CreateLabelList();
    void ResetQuantityLabels();

protected:

        void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    Ui::QuantityScreen *ui;

    QSignalMapper m_sizeMapper;
    QHBoxLayout m_sizeLayout;

    QList<Size const*> m_sizeList;
    QList<QLabel *> m_quantityLabels;
    QList<OptionBoxWidget *> m_sizeOptionWidgetList;




};

#endif // QUANTITYSCREEN_H
