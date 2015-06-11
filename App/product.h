#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <QString>
#include <QList>

#include "flavor.h"
#include "size.h"

class Product
{

public:

    typedef enum {

        e_ProductIDNone = 0,
        e_ProductIDCookie = 1

    } ProductID;

    const ProductID m_productId;


    explicit Product(const QString &productName, const QString &imageUrl, ProductID productId);
    virtual ~Product() {}
    inline QString GetProductName() const { return m_productName;}
    inline QString GetProductImage() const {return m_imageUrl;}
    virtual QList<const Flavor *> GetProductFlavors() const = 0;
    virtual QList<const Size *> GetProductSizes() const = 0;

private:

    QString m_productName;  // Name of the product. e.x cookie, yogurt, ice cream
    QString m_imageUrl;     // Generic image for the product
};

class Cookie: public Product
{
    public:

        Cookie();
        ~Cookie();

        QList<const Flavor *> GetProductFlavors() const;
        QList<const Size*> GetProductSizes() const;

        static const double COST_PER_COOKIE;

    private:

        static const QString COOKIE;
        static const QString CC_URL;
        static const QString PB_URL;
        static const QString CIN_URL;
        static const QString CHOCOLATE;
        static const QString DARK_CHOCOLATE;
        static const QString WHITE_CHOCOLATE;

        Flavor m_chocolateChip;
        Flavor m_peanutButter;
        Flavor m_cinnamon;

        Size m_sizeSmall;
        Size m_sizeLarge;

        QList<Flavor const*> m_cookieFlavors;
        QList<Size const*> m_sizes;
};

#endif // PRODUCT_H
