#include "optionboxwidgetplugin.h"
#include "optionboxwidget.h"


#include <QtPlugin>

OptionBoxPlugin::OptionBoxPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void OptionBoxPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool OptionBoxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *OptionBoxPlugin::createWidget(QWidget *parent)
{
    return new OptionBoxWidget(parent);
}

QString OptionBoxPlugin::name() const
{
    return "OptionBox";
}

QString OptionBoxPlugin::group() const
{
    return "Display Widgets [Examples]";
}

QIcon OptionBoxPlugin::icon() const
{
    return QIcon();
}

QString OptionBoxPlugin::toolTip() const
{
    return "";
}

QString OptionBoxPlugin::whatsThis() const
{
    return "";
}

bool OptionBoxPlugin::isContainer() const
{
    return false;
}

QString OptionBoxPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"OptionBox\" name=\"optionBox\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string></string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The option box is a fancy selection box.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}

QString OptionBoxPlugin::includeFile() const
{
    return "optionboxwidget.h";
}

