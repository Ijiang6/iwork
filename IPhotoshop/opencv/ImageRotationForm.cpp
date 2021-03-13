#include "ImageRotationForm.h"
#include "ui_ImageRotationForm.h"
#include"CGlobal.h"
ImageRotationForm::ImageRotationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageRotationForm)
{
    ui->setupUi(this);
    initConnection();
}

ImageRotationForm::~ImageRotationForm()
{
    delete ui;
}



void ImageRotationForm::initConnection()
{
    connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&ImageRotationForm::slot_rotationAngle);
}

void ImageRotationForm::slot_rotationAngle(int value)
{

    OpencvConvertFun::matImageRorateAngle(CGlobal::getInstance()->g_MatSrc,CGlobal::getInstance()->g_MatDst,value);
    emit sig_updateImg();
}
