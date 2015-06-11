#ifndef PACKAGESCREEN_H
#define PACKAGESCREEN_H

#include <QWidget>

#include "screen.h"
#include "optionboxwidget.h"

#include <QWidget>
#include <QSharedPointer>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QString>
#include <QLabel>

class QHBoxLayout;

namespace Ui {
class packagescreen;
}

class PackageScreen : public Screen
{
    Q_OBJECT

public:

    explicit PackageScreen(const Product &product, QWidget *parent = 0, const QString &screenName ="Package Screen");
    ~PackageScreen();

    bool Init();
    void Reset();

signals:

    void PackageSelected();
    void CrispnessSelected();

private slots:

    void NextButtonReleased();
    void BackButtonReleased();
    void CrispnessChanged();
    void PackageSelection();

protected:

        void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:

    Ui::packagescreen *ui;

    QSignalMapper m_packageMapper;
    QHBoxLayout m_packageLayout;

    //QList<const *> m_sizeList;
    QList<QLabel *> m_packageLabels;
    QList<OptionBoxWidget *> m_sizeOptionWidgetList;
};

#endif // PACKAGESCREEN_H
