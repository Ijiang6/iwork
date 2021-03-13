#ifndef NETCARDFORM_H
#define NETCARDFORM_H

#include <QWidget>
#include"NetCard.h"
#include<QTableWidgetItem>
#include"SGlobal.h"
namespace Ui {
class NetCardForm;
}

class NetCardForm : public QWidget
{
    Q_OBJECT

public:
    explicit NetCardForm(QWidget *parent = nullptr);
    ~NetCardForm();
    void init();
    void updateTable();
signals:
    void  sig_dispalyMsg(const QString & );

public slots:
    void slot_itemdoubled(QTableWidgetItem *item);
private:
    Ui::NetCardForm *ui;
    NetCard *pCardProc;
};

#endif // NETCARDFORM_H
