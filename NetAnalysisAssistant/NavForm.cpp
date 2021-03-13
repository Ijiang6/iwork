#include "NavForm.h"
#include "ui_NavForm.h"
#include"SGlobal.h"
NavForm::NavForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavForm)
{
    ui->setupUi(this);
    init();
}

NavForm::~NavForm()
{
    delete ui;
}

void NavForm::init()
{
    connect(ui->toolButton_card,&QToolButton::clicked,this,&NavForm::btnClicked);
    connect(ui->toolButton_tcp,&QToolButton::clicked,this,&NavForm::btnClicked);
    connect(ui->toolButton_udp,&QToolButton::clicked,this,&NavForm::btnClicked);
}

void NavForm::btnClicked()
{
    int index = -1;
    QToolButton * btn = qobject_cast<QToolButton *>(sender());
    if(btn == ui->toolButton_card)
    {
        index = 0;
    }
    else if (btn == ui->toolButton_tcp)
    {
        index = 1;
    }
    else if(btn == ui->toolButton_udp)
    {
        index = 2;
    }
       emit sig_curWgtIndex(index);
}
// capture package
void NavForm::on_toolButton_capture_clicked()
{
    SGlobal::getInstace()->g_break = false;
    emit sig_capture();
}

void NavForm::on_toolButton_clicked()
{
    SGlobal::getInstace()->g_break = true;
}
