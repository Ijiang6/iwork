#include "ImageCroppingForm.h"
#include "ui_ImageCroppingForm.h"

ImageCroppingForm::ImageCroppingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageCroppingForm)
{
    ui->setupUi(this);
}

ImageCroppingForm::~ImageCroppingForm()
{
    delete ui;
}
