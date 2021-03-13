#ifndef TCPFORM_H
#define TCPFORM_H

#include <QWidget>
#include"SGlobal.h"
#include"pcap.h"
#include"tchar.h"
#include"DataFormat.h"
namespace Ui {
class TcpForm;
}

class TcpForm : public QWidget
{
    Q_OBJECT

public:
    explicit TcpForm(QWidget *parent = nullptr);
    ~TcpForm();
    void updateIP(ip_header *ih);
    void updateTcp(tcp_header *th);
    void updateEh(Ethernet_header * eh);
    void initToolTips();
public slots:
    void capturePackageLoop();
    void capturePackage();
    void slot_capture();
   signals :
    void sig_logMsg(const QString &);
private:
    Ui::TcpForm *ui;
};

#endif // TCPFORM_H
