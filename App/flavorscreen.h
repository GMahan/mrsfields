#ifndef FLAVORSCREEN_H
#define FLAVORSCREEN_H

#include "screen.h"
#include "optionboxwidget.h"
#include "flavor.h"

#include<QSharedPointer>
#include<QSignalMapper>
#include<QHBoxLayout>

class OptionBox;

namespace Ui {
class FlavorScreen;
}

class FlavorScreen : public Screen
{
    Q_OBJECT

    public:

        explicit FlavorScreen(const Product &product,
                              QWidget *parent = 0,
                              const QString &screenName ="Flavor Screen");
        ~FlavorScreen();

        bool Init();
        void Reset();

    signals:

        void FlavorSelection(QString flavor);

    private slots:

        void BackButtonReleased();
        void NextButtonReleased();
        void FlavorSelected(int flavorIndex);
        void FlavorOptionSelected(int optionIndex);

protected:

        void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    private:
        Ui::FlavorScreen *ui;
        QList<const Flavor* > m_flavors;
        QList<OptionBoxWidget* > m_flavorWidgetList;
        QList<OptionBoxWidget* > m_optionWidgetList;

        QSignalMapper m_flavorMapper;
        QHBoxLayout m_flavorLayout;
        QHBoxLayout m_optionsLayout;

        QSharedPointer<QSignalMapper> m_optionMapper;

        int m_flavorSelectionIndex;
        int m_optionSelectionIndex;
        bool m_flavorSelected;
        bool m_optionSelected;

        void InitializeFlavors();
        void UpdateNextButtonState();
        void ShowFlavorOptions();
        void ClearFlavorOptions();


};

#endif // FLAVORSCREEN_H
