#include "NetCardForm.h"
#include "ui_NetCardForm.h"

NetCardForm::NetCardForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetCardForm)
{
    ui->setupUi(this);
    pCardProc =nullptr;
    init();
}

NetCardForm::~NetCardForm()
{
    delete ui;
}

void NetCardForm::init()
{
    if(pCardProc == nullptr)
    {
        pCardProc =new NetCard;
        connect(pCardProc,&NetCard::sig_dispalyMsg,this,&NetCardForm::sig_dispalyMsg);
    }

    connect(ui->tableWidget,&QTableWidget::itemDoubleClicked,this,&NetCardForm::slot_itemdoubled);
    updateTable();

}
void NetCardForm::slot_itemdoubled(QTableWidgetItem *item)
{
    if(item == nullptr)
    {
        return ;
    }
    int row = item->row();
    SGlobal::getInstace()->g_curCardID = row;
}
void NetCardForm::updateTable()
{
    ui->tableWidget->clearContents();
    QStringList cards = pCardProc->updateCardmsg();
    foreach( QString str, cards)
    {
        QStringList temp = str.split("#");
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        for(int index = 0; index < temp.size();++index)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(temp.at(index));
            ui->tableWidget->setItem(row,index,item);
        }
    }
    ui->tableWidget->resizeColumnsToContents();
}
