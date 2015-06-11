#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>

class Package
{
public:

    typedef enum {

        ePackage_Box,
        ePackage_Basket,
        ePackage_None

    } Package_e;

    Package();
    explicit Package(Package_e packageType, QString name, QString imageUrl, double price = 0.0);

    ~Package();

    void SetPackagePrice(double price);
    void SetPackageName(QString name);
    void SetPackageType(Package_e type);
    void SetPackageImage(QString imageUrl);

    int GetPrice() const;
    QString GetName() const;
    Package_e GetType() const;
    QString GetImageUrl() const;

private:

    Package_e m_type;
    QString m_name;
    QString m_image;
    double m_price;
};

#endif // PACKAGE_H
