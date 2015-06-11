#include "package.h"

/**
 * @brief Package::Package
 */
Package::Package()
{

}

/**
 * @brief Package::Package
 * @param packageType
 * @param name
 * @param imageUrl
 * @param price
 */
Package::Package(Package::Package_e packageType, QString name, QString imageUrl, double price) :
    m_type(packageType),
    m_name(name),
    m_image(imageUrl),
    m_price(price)
{

}

/**
 * @brief Package::~Package
 */
Package::~Package()
{

}

/**
 * @brief Package::SetPackagePrice
 * @param price
 */
void Package::SetPackagePrice(double price)
{
    if (price > 0) {
        m_price = price;
    }
}

/**
 * @brief Package::SetPackageName
 * @param name
 */
void Package::SetPackageName(QString name)
{
    m_name = name;
}

/**
 * @brief Package::SetPackageType
 * @param type
 */
void Package::SetPackageType(Package::Package_e type)
{
    m_type = type;
}

/**
 * @brief Package::SetPackageImage
 * @param imageUrl
 */
void Package::SetPackageImage(QString imageUrl)
{
    m_image = imageUrl;
}

/**
 * @brief Package::GetPrice
 * @return
 */
int Package::GetPrice() const
{
    return m_price;
}

/**
 * @brief Package::GetName
 * @return
 */
QString Package::GetName() const
{
    return m_name;
}

/**
 * @brief Package::GetType
 * @return
 */
Package::Package_e Package::GetType() const
{
    return m_type;
}

/**
 * @brief Package::GetImageUrl
 * @return
 */
QString Package::GetImageUrl() const
{
    return m_image;
}


