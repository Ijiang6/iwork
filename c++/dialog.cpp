#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::init()
{
    this->setWindowTitle("FILE ASSISTANT");
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(slot_tbfile()));
    connect(ui->toolButton_3,SIGNAL(clicked()),this,SLOT(slot_tbok()));
    connect(ui->toolButton_2,SIGNAL(clicked()),this,SLOT(close()));
    m_server.create_sock();
    m_server.sock_addr_init(8989);
    m_server.sock_bind();
    m_server.s_listen(MAXLINKS);
    m_server.init_select();
    pTimer =new QTimer;
    connect(pTimer,SIGNAL(timeout()),this,SLOT(slot_timerAlarm()));
 pTimer->start(1000);
}
void Dialog::slot_timerAlarm()
{
    m_server.selectIO();
//    pTimer->stop();
    updateProcess();
}
void Dialog::updateProcess()
{
    ui->progressBar->setValue(m_server.getProcess());
}
void Dialog::slot_tbfile()
{
    QString file_name = QFileDialog::getOpenFileName(this,"标题",".","*.*");
    ui->label->setText(file_name);
}
void Dialog::slot_tbok()
{
    //QMessageBox::question(this, "question", "are you sure trans this file?", QMessageBox::Yes, QMessageBox::Yes);

    QString strPath=ui->label->text();
    QStringList listPath=strPath.split('/');
    QStringList listFileMsg=listPath.last().split('.');
    if(listFileMsg.size()<2)
    {
        return;
    }
    string fileType=listFileMsg.at(1).toStdString();
    string fileName=listFileMsg.at(0).toStdString();

    m_server.setFileMsg(fileName,fileType);
    m_server.readfiletest(strPath.toStdString());
}
