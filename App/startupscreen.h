#ifndef STARTUPSCREEN_H
#define STARTUPSCREEN_H

#include "screen.h"

namespace Ui {
class StartupScreen;
}

class StartupScreen : public Screen
{
    Q_OBJECT

    public:
        explicit StartupScreen(const Product &product, QWidget *parent = 0, const QString &screenName ="Start Screen");
        ~StartupScreen();
        bool Init();
        void Reset();

    private slots:

        void NextButtonReleased();

    private:
        Ui::StartupScreen *ui;
};

#endif // STARTUPSCREEN_H
