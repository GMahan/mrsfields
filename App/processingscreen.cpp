#include "processingscreen.h"
#include "ui_processingscreen.h"

ProcessingScreen::ProcessingScreen(const Product &product, QWidget *parent, const QString &screenName) :
    Screen(eScreenType_Processing, product, parent, screenName),
    ui(new Ui::ProcessingScreen)
{
    ui->setupUi(this);
}

ProcessingScreen::~ProcessingScreen()
{
    delete ui;
}

bool ProcessingScreen::Init()
{
    hide();
    return true;
}

void ProcessingScreen::Reset()
{

}
