#ifndef IMAGEROTATIONFORM_H
#define IMAGEROTATIONFORM_H

#include <QWidget>

namespace Ui {
class ImageRotationForm;
}

class ImageRotationForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImageRotationForm(QWidget *parent = 0);
    ~ImageRotationForm();
    void initConnection();
public slots:
    void slot_rotationAngle(int value);
signals:
    void sig_updateImg();
private:
    Ui::ImageRotationForm *ui;
};

#endif // IMAGEROTATIONFORM_H
