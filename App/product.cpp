        #include "product.h"

const QString Cookie::COOKIE = ":/Flavor/Images/Cookie.png";

const QString Cookie::CC_URL = ":/Flavor/Images/Chocolate_Chip.png";
const QString Cookie::PB_URL = ":/Flavor/Images/PeanutButter.png";
const QString Cookie::CIN_URL = ":/Flavor/Images/Cinnamon-Sticks.png";

const QString Cookie::CHOCOLATE = ":/Flavor/Images/Chocolate.png";
const QString Cookie::DARK_CHOCOLATE = ":/Flavor/Images/DarkChocolate.png";
const QString Cookie::WHITE_CHOCOLATE = ":/Flavor/Images/WhiteChocolate.png";

const double Cookie::COST_PER_COOKIE = 2.0;

Product::Product(const QString &productName, const QString &imageUrl, Product::ProductID productId) :
    m_productId(productId),
    m_productName(productName),
    m_imageUrl(imageUrl)
{

}

Cookie::Cookie() :
    Product("Cookie", COOKIE, e_ProductIDCookie),
    m_chocolateChip(FlavorProperties("Chocolate", CC_URL)),
    m_peanutButter(FlavorProperties("Peanut Butter", PB_URL)),
    m_cinnamon(FlavorProperties("Cinnamon", CIN_URL)),
    m_sizeSmall(Size::e_SizeSmall, "Small", COOKIE, 1.30),
    m_sizeLarge(Size::e_SizeLarge, "Large", COOKIE, 1.90)

{
    // Setup flavor options for chocolate chip
    m_chocolateChip.AddFlavorOption(FlavorProperties("White Chocolate", WHITE_CHOCOLATE));
    m_chocolateChip.AddFlavorOption(FlavorProperties("Dark Chocolate", DARK_CHOCOLATE));
    m_chocolateChip.AddFlavorOption(FlavorProperties("Chocolate", CHOCOLATE));

    // Add flavorst to the list
    m_cookieFlavors.append(&m_chocolateChip);
    m_cookieFlavors.append(&m_peanutButter);
    m_cookieFlavors.append(&m_cinnamon);

    // Add sizes to the list
    m_sizes.append(&m_sizeSmall);
    m_sizes.append(&m_sizeLarge);
}

Cookie::~Cookie()
{

}

QList<const Flavor *> Cookie::GetProductFlavors() const
{
    return m_cookieFlavors;
}

QList<const Size *> Cookie::GetProductSizes() const
{
    return m_sizes;
}



