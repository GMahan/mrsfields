#include "screen.h"

/**
 * @brief Screen::Screen
 * @param screenType: specifies the screen type
 * @param screenName: name of the screen
 * @param parent: parent widget this widget belongs to
 */
Screen::Screen(ScreenType_e screenType, const Product &product, QWidget *parent, const QString &screenName)
    :QWidget(parent),
     m_product(product),
     m_screenType(screenType),
     m_screenName(screenName)
{

}

/**
 * @brief Screen::~Screen
 */
Screen::~Screen()
{

}

/**
 * @brief Screen::GetScreenType
 * @return screen type
 */
Screen::ScreenType_e Screen::GetScreenType() const
{
    return m_screenType;
}

/**
 * @brief Screen::GetScreenName
 * @return screen name
 */
QString Screen::GetScreenName() const
{
    return m_screenName;
}


