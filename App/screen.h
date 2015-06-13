#ifndef SCREEN_H
#define SCREEN_H

#include "product.h"
#include "size.h"
#include <QWidget>

class Screen;

class Screen : public QWidget
{
    Q_OBJECT

    public:

        typedef enum {

            eScreenType_Start = 0,
            eScreenType_Flavor,
            eScreenType_Quantity_Size,
            eScreenType_Package_Crisp,
            eScreenType_OrderSummary,
            eScreenType_Processing,
            eScreenType_Max

        } ScreenType_e;

        explicit Screen(ScreenType_e screenType, const Product &product, QWidget *parent = 0, const QString &screenName = "noName");
        virtual ~Screen();
        virtual bool Init() = 0;
        virtual void ResetScreen() = 0;

        ScreenType_e GetScreenType() const;
        QString GetScreenName() const;

    signals:

        void Next();
        void Back();
        void Reset();
        void FlavorSelection(QString flavor);
        void QuantitySelected(int);
        void SizeSelected(const Size &);

    protected:

        const Product &m_product;

    private:

        ScreenType_e m_screenType;
        QString m_screenName;

};

Q_DECLARE_METATYPE(Size)

#endif // SCREEN_H
