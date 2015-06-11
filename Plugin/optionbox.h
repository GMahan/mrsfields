#ifndef OPTIONBOX_H
#define OPTIONBOX_H

#include <QWidget>

namespace Ui {
class OptionBox;
}

class OptionBox : public QWidget
{
    Q_OBJECT

public:
    explicit OptionBox(QWidget *parent = 0);
    ~OptionBox();

private:
    Ui::OptionBox *ui;
};

#endif // OPTIONBOX_H
