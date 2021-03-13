#ifndef IMAGECROPPINGFORM_H
#define IMAGECROPPINGFORM_H

#include <QWidget>

namespace Ui {
class ImageCroppingForm;
}

class ImageCroppingForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImageCroppingForm(QWidget *parent = 0);
    ~ImageCroppingForm();

private:
    Ui::ImageCroppingForm *ui;
};

#endif // IMAGECROPPINGFORM_H
