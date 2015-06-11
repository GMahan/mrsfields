#ifndef FLAVOR_H
#define FLAVOR_H

#include <QString>
#include <QList>

class FlavorProperties
{
    public:
        explicit FlavorProperties(const QString &name, const QString &imageUrl):
            m_name(name),
            m_imageUrl(imageUrl) {}
        ~FlavorProperties() {}
        QString GetOptionName() const {return m_name;}
        QString GetOptionImageUrl() const {return m_imageUrl;}
    private:
        QString m_name;
        QString m_imageUrl;
};

class Flavor
{
public:

    explicit Flavor(FlavorProperties flavor);
    ~Flavor();

    QString GetFlavorName() const;
    QString GetFlavorImageUrl() const;
    QList<const FlavorProperties *> GetFlavorOptions() const;
    void AddFlavorOption(FlavorProperties option);

private:
    FlavorProperties *m_properties;
    QList<FlavorProperties> m_options;
};



#endif // FLAVOR_H
