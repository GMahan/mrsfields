#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include <QTypeInfo>
#include <QString>

class Order
{
    public:
        Order() {}
        ~Order() {}
        static double GetOrderTotal() { return (m_productCost * m_quantity); }
        static void OrderReset() { m_productCost = 0; m_quantity = 0; }
        static void SetProductCost(double cost) { m_productCost = cost; }
        static void SetOrderQuantity(quint8 quantity) {m_quantity = quantity; }
        static void SetProductId(Product::ProductID id) { m_productID = id; }
        static void SetProductName(const QString &name) { m_name = name; }
    private:
        static double m_productCost;
        static quint8 m_quantity;
        static QString m_name;
        static Product::ProductID m_productID;
};

#endif // ORDER_H
