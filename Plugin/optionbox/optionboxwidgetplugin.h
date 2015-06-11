#ifndef OPTIONBOXWIDGETPLUGIN_H
#define OPTIONBOXWIDGETPLUGIN_H

#include <QDesignerCustomWidgetInterface>

class OptionBoxPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "gaganmahan")
    Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    OptionBoxPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized;
};

#endif // OPTIONBOXWIDGETPLUGIN_H
