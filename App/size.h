#ifndef SIZE_H
#define SIZE_H

#include <QString>
#include <QMetaType>

class Size
{
public:

    typedef enum {

        e_SizeSmall = 0,
        e_SizeMedium,
        e_SizeLarge

    } Size_e;

    Size();
    explicit Size(Size_e sizeType, QString name, QString imageURL, double price);
    ~Size();

    QString GetName() const;
    Size_e  GetSize() const;
    QString GetImageURL() const;
    double GetPrice() const;

    void SetImage(const QString &imageURL);

private:

    Size_e m_sizeType;
    QString m_sizeName;
    QString m_imageURL;
    double m_price;
};

Q_DECLARE_METATYPE(Size)

#endif // SIZE_H
