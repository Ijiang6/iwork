#ifndef NETCARD_H
#define NETCARD_H

#include <QObject>
#include"pcap.h"
#include<QStringList>
class NetCard : public QObject
{
    Q_OBJECT
public:
    explicit NetCard(QObject *parent = nullptr);
    QStringList  updateCardmsg();
    bool LoadNpcapDlls();
    QString  getAllInformation(pcap_if_t *d);
signals:
    void  sig_dispalyMsg(const QString & );
};

#endif // NETCARD_H
