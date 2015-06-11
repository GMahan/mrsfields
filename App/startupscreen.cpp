#include "startupscreen.h"
#include "ui_startupscreen.h"

StartupScreen::StartupScreen(const Product &product, QWidget *parent, const QString &screenName)
    :Screen(Screen::eScreenType_Start, product, parent, screenName),
     ui(new Ui::StartupScreen)
{
    ui->setupUi(this);
    connect(ui->StartButton, SIGNAL(released()), this, SLOT(NextButtonReleased()));
}

StartupScreen::~StartupScreen()
{
    delete ui;
}

bool StartupScreen::Init()
{
    hide();
    return true;
}

void StartupScreen::Reset()
{

}

void StartupScreen::NextButtonReleased()
{
    emit Next();
}
