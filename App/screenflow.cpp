#include "screenflow.h"
#include "screen.h"
#include "startupscreen.h"
#include "flavorscreen.h"
#include "quantityscreen.h"
#include <QDebug>


const ScreenFlow::TransitionTable ScreenFlow::SCREEN_TABLE[Screen::eScreenType_Max] =
{
    /*current*/                         /*previous*/                        /*next*/
    {Screen::eScreenType_Start,         Screen::eScreenType_Start,          Screen::eScreenType_Flavor},
    {Screen::eScreenType_Flavor,        Screen::eScreenType_Start,          Screen::eScreenType_Quantity_Size},
    {Screen::eScreenType_Quantity_Size, Screen::eScreenType_Flavor,         Screen::eScreenType_Package_Crisp},
    {Screen::eScreenType_Package_Crisp, Screen::eScreenType_Quantity_Size,  Screen::eScreenType_OrderSummary},
    {Screen::eScreenType_OrderSummary,  Screen::eScreenType_Quantity_Size,  Screen::eScreenType_Processing},
    {Screen::eScreenType_Processing,    Screen::eScreenType_OrderSummary,   Screen::eScreenType_Start}
};


/**
 * @brief ScreenFlow::ScreenFlow constructor
 */
ScreenFlow::ScreenFlow() :
    m_screenList(Screen::eScreenType_Max),
    m_currentScreen(0)
{
    // Initialize m_ScreenList

    for (int i = 0;  i < Screen::eScreenType_Max; i++) {

        m_screenList[i].screen = 0;
        m_screenList[i].previous = 0;
        m_screenList[i].next = 0;
    }
}

/**
 * @brief ScreenFlow::~ScreenFlow
 */
ScreenFlow::~ScreenFlow()
{

}

/**
 * @brief ScreenFlow::Start
 * Display the start screen
 */
bool ScreenFlow::Start()
{
    if (UpdateScreenStates()) {

        m_currentScreen = m_screenList[Screen::eScreenType_Start].screen;
        m_screenList[Screen::eScreenType_Start].screen->show();
        return true;
    }

    return false;
}

/**
 * @brief ScreenFlow::RegisterScreen
 * Hides all the screens and connects the signals
 * back and next to the appropriate slots.
 * @param screenList: List of UI screens that make up the workflow
 * @return Returns true if sucess else returns false
 */
bool ScreenFlow::RegisterScreen(Screen *screen)
{
    if (!AppendToScreenList(screen)) {
        return false;
    }

    connect(screen, SIGNAL(Next()), this, SLOT(DisplayNextScreen()));
    connect(screen, SIGNAL(Back()), this, SLOT(DisplayPrevScreen()));

    return true;
}

/**
 * @brief ScreenFlow::DisplayNextScreen
 * Shows the next transition screen.
 * @param screen: Pointer to current screen
 */
void ScreenFlow::DisplayNextScreen()
{
    qDebug() << m_currentScreen->GetScreenName() \
             << "--->" \
             << m_screenList[m_currentScreen->GetScreenType()].next->GetScreenName();

    m_currentScreen->hide(); // Hide current screen
    m_currentScreen = m_screenList[m_currentScreen->GetScreenType()].next;
    m_currentScreen->show();

    emit ScreenNext();
}

/**
 * @brief ScreenFlow::DisplayPrevScreen
 * Shows the previous transition screen
 * @param screen: Pointer to current screen
 */
void ScreenFlow::DisplayPrevScreen()
{
   qDebug() << m_currentScreen->GetScreenName() \
            << "--->" \
            << m_screenList[m_currentScreen->GetScreenType()].previous->GetScreenName();

   m_currentScreen->hide(); // Hide current screen
   m_currentScreen = m_screenList[m_currentScreen->GetScreenType()].previous;
   m_currentScreen->show();

   emit ScreenPrevious();
}

bool ScreenFlow::AppendToScreenList(Screen *screenToAdd)
{
    if (m_screenList[screenToAdd->GetScreenType()].screen != 0) {

        qDebug() << QString("Screen %1 already exists not registering").arg(screenToAdd->GetScreenName());
        return false;
    }

    m_screenList[screenToAdd->GetScreenType()].screen = screenToAdd;

    return true;

}

bool ScreenFlow::UpdateScreenStates()
{
    // Make sure we have all the screens

    for (int i = 0; i < Screen::eScreenType_Max; i++) {

        if (m_screenList[i].screen == 0) {

            qDebug() << "Screens missing";
            return false;
        }
    }

    // Create the transition table

    for (int i = 0; i < Screen::eScreenType_Max; i++) {

        int screenIndex = static_cast<int>(SCREEN_TABLE[i].screen);

        m_screenList[screenIndex].previous = m_screenList[SCREEN_TABLE[i].previous].screen;
        m_screenList[screenIndex].next = m_screenList[SCREEN_TABLE[i].next].screen;
    }

    return true;
}



