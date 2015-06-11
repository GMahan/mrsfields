#include "size.h"

Size::Size()
{

}

Size::Size(Size_e sizeType, QString name, QString imageURL, double price) :
    m_sizeType(sizeType),
    m_sizeName(name),
    m_imageURL(imageURL),
    m_price(price)
{

}

Size::~Size()
{

}

QString Size::GetName() const
{
    return m_sizeName;
}

Size::Size_e Size::GetSize() const
{
    return m_sizeType;
}

QString Size::GetImageURL() const
{
    return m_imageURL;
}

double Size::GetPrice() const
{
    return m_price;
}

void Size::SetImage(const QString &imageURL)
{
    m_imageURL = imageURL;
}

