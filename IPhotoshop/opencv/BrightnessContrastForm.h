#ifndef BRIGHTNESSCONTRASTFORM_H
#define BRIGHTNESSCONTRASTFORM_H

#include <QWidget>

namespace Ui {
class BrightnessContrastForm;
}

class BrightnessContrastForm : public QWidget
{
    Q_OBJECT

public:
    explicit BrightnessContrastForm(QWidget *parent = 0);
    ~BrightnessContrastForm();
    void initConnection();

public slots:
    void slot_brightnessContrast();
   signals:
    void sig_updateImg();

private:
    Ui::BrightnessContrastForm *ui;
};

#endif // BRIGHTNESSCONTRASTFORM_H
