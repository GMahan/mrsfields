#include "flavor.h"

#include <QDebug>

Flavor::Flavor(FlavorProperties flavor) :m_properties(new FlavorProperties(flavor))
{

}

Flavor::~Flavor()
{
    delete m_properties;
}

QString Flavor::GetFlavorName() const
{
    return m_properties->GetOptionName();
}

QString Flavor::GetFlavorImageUrl() const
{
    return m_properties->GetOptionImageUrl();
}

QList<const FlavorProperties *> Flavor::GetFlavorOptions() const
{
    QList <const FlavorProperties *> optionList;

    QList<FlavorProperties>::const_iterator i;

    for (i = m_options.begin(); i != m_options.end(); i++)
    {
        optionList.append(&(*i));
        qDebug() << i->GetOptionImageUrl();

    }


    return optionList;
}

void Flavor::AddFlavorOption(FlavorProperties option)
{
    m_options.append(option);
}


