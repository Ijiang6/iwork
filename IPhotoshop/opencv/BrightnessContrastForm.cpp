#include "BrightnessContrastForm.h"
#include "ui_BrightnessContrastForm.h"
#include"OpencvConvertFun.h"
#include"CGlobal.h"
BrightnessContrastForm::BrightnessContrastForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrightnessContrastForm)
{
    ui->setupUi(this);
    initConnection();
}

BrightnessContrastForm::~BrightnessContrastForm()
{
    delete ui;
}
/**
 * @brief BrightnessContrastForm::initConnection
 */
void BrightnessContrastForm::initConnection()
{
    connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
    connect(ui->spinBox1,SIGNAL(valueChanged(int)),ui->horizontalSlider_2,SLOT(setValue(int)));
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
    connect(ui->horizontalSlider_2,&QSlider::valueChanged,ui->spinBox1,&QSpinBox::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&BrightnessContrastForm::slot_brightnessContrast);
    connect(ui->horizontalSlider_2,&QSlider::valueChanged,this,&BrightnessContrastForm::slot_brightnessContrast);
}
/**
 * @brief BrightnessContrastForm::slot_contrast
 * @param value
 */
void BrightnessContrastForm::slot_brightnessContrast()
{
    int alpha = ui->horizontalSlider_2->value();
    int beta = ui->horizontalSlider->value();
    OpencvConvertFun::matBrightnessContrast(CGlobal::getInstance()->g_MatSrc,CGlobal::getInstance()->g_MatDst,alpha,beta);
    emit sig_updateImg();
}
