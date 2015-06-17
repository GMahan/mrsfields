#ifndef SCREENFLOW_H
#define SCREENFLOW_H

#include <QObject>
#include <QList>
#include <QVector>

#include "screen.h"

class ScreenFlow : public QObject
{
   Q_OBJECT

   public:

      typedef struct {

        Screen::ScreenType_e screen;
        Screen::ScreenType_e previous;
        Screen::ScreenType_e next;

      } TransitionTable;

      typedef struct {

        Screen* screen;
        Screen* previous;
        Screen* next;

     } ScreenState;

      static const TransitionTable SCREEN_TABLE[Screen::eScreenType_Max];

       ScreenFlow();
       ~ScreenFlow();

       bool RegisterScreen(Screen *screen);
       bool Start();

   signals:

       void ScreenNext();
       void ScreenPrevious();

   private slots:

       void DisplayNextScreen();
       void DisplayPrevScreen();
       void ResetUI();

   private:

       QVector<ScreenState> m_screenList;
       //QList<Screen *> m_screenList;
       Screen *m_currentScreen;

       bool AppendToScreenList(Screen *screenToAdd);
       bool UpdateScreenStates();

};

#endif // SCREENFLOW_H
