#include "MainWindow.h"
#include "ui_MainWindow.h"
#include<QDateTime>
#include"SGlobal.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    SGlobal::getInstace()->g_break = false;
   connect(ui->cardwgt,&NetCardForm::sig_dispalyMsg,this,&MainWindow::slot_dispalyMsg);
   connect(ui->widget_nav,&NavForm::sig_curWgtIndex,this,&MainWindow::slot_curWgtIndex);
   connect(ui->widget_nav,&NavForm::sig_capture,this,&MainWindow::slot_capture);
}
void MainWindow::slot_dispalyMsg(const QString &msg)
{
    QString datestr = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    QString msgs = QString("%1>>>>>>>>>>%2").arg(datestr).arg(msg);
    ui->statusbar->showMessage(msgs);
}

void MainWindow::slot_curWgtIndex(int index)
{
    if(index < 0)
    {
        return ;
    }
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::slot_capture()
{
    if(ui->stackedWidget->currentIndex() == 1)
    {
        ui->tcpwgt->slot_capture();
    }
    else if(ui->stackedWidget->currentIndex() == 2)
    {
        ui->udpWgt->slot_realPackage();
    }
}

