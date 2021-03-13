#include "WarpAffineForm.h"
#include "ui_WarpAffineForm.h"
#include"CGlobal.h"
WarpAffineForm::WarpAffineForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarpAffineForm)
{
    ui->setupUi(this);
    initConection();
}

WarpAffineForm::~WarpAffineForm()
{
    delete ui;
}

void WarpAffineForm::initConection()
{
    connect(ui->toolButton,&QToolButton::clicked,this,&WarpAffineForm::slot_warrf);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&WarpAffineForm::slot_delFrame);
}

void WarpAffineForm::slot_warrf()
{
    bool bOK=OpencvConvertFun::matImageRorateAngleAuto(CGlobal::getInstance()->g_MatSrc,CGlobal::getInstance()->g_MatDst);
    if(bOK)
    {
        emit sig_updateImg();
    }
}

void WarpAffineForm::slot_delFrame()
{
    bool bOK =OpencvConvertFun::matImageDelFrame(CGlobal::getInstance()->g_MatSrc,CGlobal::getInstance()->g_MatDst);
    if(bOK)
    {
        emit sig_updateImg();
    }

}
