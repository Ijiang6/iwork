#include "RealForm.h"
#include "ui_RealForm.h"
#include<iostream>
#include<string.h>
#include<thread>
#define SIZE 1024
char buf2[SIZE / 2];
#define NTOHS(A) ((((A)&0xFF00)>>8) | (((A)&0x00FF)<<8))
RealForm::RealForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealForm)
{
    ui->setupUi(this);
}
// itoa 封装，转为指定进制的sting 类型
template <class T>
std::string dataToString(T data,int radix) {
    memset(buf2,0x00,sizeof buf2);
    itoa(data,buf2,radix);
    return buf2;
}
RealForm::~RealForm()
{
    delete ui;
}

void RealForm::startCapture()
{
    pcap_t *adhandle;
    char errbuf[255];
    struct tm ltime;
    char timestr[16];
    time_t local_tv_sec;
    u_int netmask;
    struct bpf_program fcode;
    pcap_if_t *d = SGlobal::getInstace()->getIndexDevcs(SGlobal::getInstace()->g_curCardID,SGlobal::getInstace()->g_alldevs);
    /* Open the device */
    if ( (adhandle= pcap_open(d->name,			// name of the device
                              65536,				// portion of the packet to capture.
                              // 65536 guarantees that the whole packet will be captured on all the link layers
                              PCAP_OPENFLAG_PROMISCUOUS, 	// promiscuous mode
                              1000,				// read timeout
                              NULL,				// authentication on the remote machine
                              errbuf				// error buffer
                              ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by Npcap\n", d->name);
        return ;
    }

    printf("\nlistening on %s...\n", d->description);


    int res;
    pcap_pkthdr *header;
    const u_char *pkt_data;
    ip_header *ih;
    tcp_header *th;

    Ethernet_header * eh;
    u_int ip_len;
    u_short sport,dport;
    /* Retrieve the packets */
    while((res = pcap_next_ex( adhandle, &header, &pkt_data)) >= 0){

        if(SGlobal::getInstace()->g_break)
        {
            break;
        }
        if(res == 0)
            /* Timeout elapsed */
            continue;

        /* convert the timestamp to readable format */
        local_tv_sec = header->ts.tv_sec;
        localtime_s(&ltime, &local_tv_sec);
        strftime( timestr, sizeof timestr, "%H:%M:%S", &ltime);

        printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);
        /*parse ethernet header */
        eh = (Ethernet_header*) (pkt_data);

    eh->th_type = NTOHS(eh->th_type);  // 网络字节序转为主机字节序

    // 以太网协议类型
    QString  type( "0x" +QString::fromStdString( dataToString(eh->th_type,16)));

    QString  stype = " ";
    if(type =="0x800" )
    {
        stype = "IP";
    }
    else if(type == "0x806")
    {
        stype = "ARP";
    }
    else if(type == "0x8035")
    {
        stype = "RARP";
    }
    // 目标地址 MAC
    memset(buf2,0x00,sizeof buf2);
#define A(I) eh->dMac[I]
    sprintf(buf2," %02X:%02X:%02X:%02X:%02X:%02X ",A(0),A(1),A(2),A(3),A(4),A(5));

     QString  dMAC(buf2);

    // 源地址 MAC
    memset(buf2,0x00,sizeof buf2);
#define B(I) eh->sMac[I]
    sprintf(buf2," %02X:%02X:%02X:%02X:%02X:%02X ",B(0),B(1),B(2),B(3),B(4),B(5));
     QString  sMAC(buf2);

    QString  package = QString("%1:[%2 > %3] | type:[%4]%5 | %6 (us) | len:%7")
            .arg(timestr)
            .arg(sMAC)
            .arg(dMAC)
            .arg(type)
            .arg(stype)
            .arg(QString("%1").arg(header->ts.tv_usec))
            .arg(QString("%1").arg(header->len));
    ui->listWidget->addItem(package);
    if(ui->listWidget->count() > 100)
    {
        ui->listWidget->clear();
    }
    }
    if(res == -1){
        printf("Error reading the packets: %s\n", pcap_geterr(adhandle));
        return ;
    }
}

void RealForm::slot_realPackage()
{
    std::thread t(&RealForm::startCapture,this);
    t.detach();
}
