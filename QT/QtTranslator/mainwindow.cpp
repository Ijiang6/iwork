#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QTranslator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString strFile=QFileDialog::getOpenFileName(this,tr("select file"),".",tr("fileType(*.qm)"));
     QTranslator *pTran=new QTranslator;
    if(pTran->load(strFile))
    {
        qApp->installTranslator(pTran);
    }
    /****key point*****/
    ui->retranslateUi(this);

}
