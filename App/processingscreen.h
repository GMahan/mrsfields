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

    static const int PROCESSING_TIME = 10;

    explicit ProcessingScreen(const Product &product, QWidget *parent = 0, const QString &screenName = "Processing Screen");
    ~ProcessingScreen();

    bool Init();
    void ResetScreen();

protected:

    void showEvent(QShowEvent *) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private slots:

    void UpdateRemainingTime();
    void Done();

private:

    Ui::ProcessingScreen *ui;
    QTimer *m_processingTimer;
    unsigned int m_secondCount;

    void UpdateFontProperties();
    void UpdateTimeRemainingString();
};

#endif // PROCESSINGSCREEN_H
