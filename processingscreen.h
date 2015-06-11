#ifndef PROCESSINGSCREEN_H
#define PROCESSINGSCREEN_H

#include "screen.h"

#include <QWidget>

namespace Ui {
class ProcessingScreen;
}

class ProcessingScreen : public Screen
{
    Q_OBJECT

public:
    explicit ProcessingScreen(const Product &product, QWidget *parent = 0, const QString &screenName = "Processing Screen");
    ~ProcessingScreen();

    bool Init();
    void Reset();

private:
    Ui::ProcessingScreen *ui;
};

#endif // PROCESSINGSCREEN_H
