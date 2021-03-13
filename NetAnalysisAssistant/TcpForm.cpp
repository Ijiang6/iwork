#include "TcpForm.h"
#include "ui_TcpForm.h"
#include<thread>
#include<iostream>
#include<string.h>
#define SIZE 1024
char buf[SIZE / 2];

// itoa 封装，转为指定进制的sting 类型
template <class T>
std::string dataToString(T data,int radix) {
    memset(buf,0x00,sizeof buf);
    itoa(data,buf,radix);
    return buf;
}
// 点分十进制
std::string iptos(long in)
{
    u_char *p;
    p = (u_char *)&in;
    memset(buf,0x00,sizeof buf);
    sprintf(buf, "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
    return buf;
}
TcpForm::TcpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpForm)
{
    ui->setupUi(this);
    initToolTips();
}

TcpForm::~TcpForm()
{
    delete ui;
}


void TcpForm::updateIP(ip_header *ih)
{
    //version
    QString sver;
    if((ih->ver_ihl & (0x40)) == 0x40) sver = "ipv4";
    else if((ih->ver_ihl & (0x60)) == 0x60) sver = "ipv6";
    else sver= "unknow";
    ui->IPver->setText(sver);

    //ip head length
    int len = (ih->ver_ihl & 0xf) * 4;
    ui->IPihl->setText(QString("%1").arg(len));
    //tos
    ui->IPtos->setText(QString("%1").arg((int)ih->tos));
    //total len
    ui->IPtlen->setText(QString("%1").arg(ih->tlen));
    //16
    ui->IPidentification->setText(QString("%1").arg(ih->identification));
    //check sum
     ui->IPchecksum->setText(QString("%1").arg(ih->crc));


     char flag = (ih->flags_fo) >> 13;
     std::string fRet = dataToString(flag,2);
     fRet = std::string(3-fRet.size(),'0') + fRet; // 补前置0
     char offset = ih->flags_fo & 0x1fff;
     std::string oRet = dataToString(offset,16);
     oRet = std::string(4 - oRet.size(),'0') + oRet;

     ui->IPflag ->setText(QString::fromStdString(fRet));
     ui->IPoffset ->setText("0x"+QString::fromStdString(oRet));
     ui->IPttl->setText( "0x" + QString::fromStdString(dataToString(ih->ttl,16)));

    ui->IPproto->setText(  QString::fromStdString(dataToString(ih->proto,10)));

    ui->IPsrc ->setText( QString("%1.%2.%3.%4").arg( ih->saddr.byte1)
                                                .arg( ih->saddr.byte2)
                                                .arg( ih->saddr.byte3)
                                                .arg( ih->saddr.byte4));
    ui->IPdst ->setText( QString("%1.%2.%3.%4").arg( ih->daddr.byte1)
                                                .arg( ih->daddr.byte2)
                                                .arg( ih->daddr.byte3)
                                                .arg( ih->daddr.byte4));
}
void TcpForm::updateTcp(tcp_header *th)
{

    ui->tcpSrcport->setText(QString("%1").arg(th->sport));

    ui->tcpDesport->setText(QString("%1").arg(th->dport));

    ui->tcpseq->setText(QString("%1").arg(th->seqNum));

    ui->tcpAck->setText(QString("%1").arg(th->ackNum));

    u_int len = th->off_res_flag & 0xF000;

    ui->tcpth->setText(QString("%1").arg(len));

    u_int urg = th->off_res_flag & 0x0020;
    urg = urg >> 5;
    u_int ack = th->off_res_flag & 0x0010;
    ack = ack >> 4;
    u_int psh = th->off_res_flag & 0x0008;
    psh = psh >> 3;
    u_int pst = th->off_res_flag & 0x0004;
    pst = pst >> 2;
    u_int syn = th->off_res_flag & 0x0002;
    syn = syn >> 1;
    u_int fin = th->off_res_flag & 0x0001;

    ui->tcpfurg->setText(QString("%1").arg(urg));
    ui->tcpfack->setText(QString("%1").arg(ack));
    ui->tcpfpsh->setText(QString("%1").arg(psh));
    ui->tcpfrst->setText(QString("%1").arg(pst));
    ui->tcpfsyn->setText(QString("%1").arg(syn));
    ui->tcpffin->setText(QString("%1").arg(fin));
  ui->tcpfwsize->setText(QString("%1").arg(th->winSize));
  ui->tcpAck->setText(QString("%1").arg(th->checkSum));
  ui->tcpagent->setText(QString("%1").arg(th->urgentPoint));

}
void TcpForm::capturePackage()
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

    // fillter  para
    if(d->addresses != NULL)
        /* Retrieve the mask of the first address of the interface */
        netmask=((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        /* If the interface is without addresses we suppose to be in a C class network */
        netmask=0xffffff;
    char packet_filter[] = "ip and tcp";//"ip and tcp";
    //compile the filter
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) <0 )
    {
        fprintf(stderr,"\nUnable to compile the packet filter. Check the syntax.\n");
        return ;
    }
    //set the filter
    if (pcap_setfilter(adhandle, &fcode)<0)
    {
        fprintf(stderr,"\nError setting the filter.\n");
        return ;
    }

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
       // update ui basic msg
        ui->label_time->setText(timestr);
        ui->label_time_2->setText(QString("%1").arg(header->ts.tv_usec));
        ui->label_len->setText(QString("%1").arg(header->len));


        /*parse ethernet header */
        eh = (Ethernet_header*) (pkt_data);
        updateEh(eh);
        /* retireve the position of the ip header */
        ih = (ip_header *) (pkt_data +
                            14); //length of ethernet header


        /* retireve the position of the udp header */
        ip_len = (ih->ver_ihl & 0xf) * 4;
        th = (tcp_header *) ((u_char*)ih + ip_len);
        std::cout << " proc tcp package"<< std::endl;
        updateIP(ih);
        updateTcp(th);
    }

    if(res == -1){
        printf("Error reading the packets: %s\n", pcap_geterr(adhandle));
        return ;
    }

}
void TcpForm::updateEh(Ethernet_header *eh)
{

#define NTOHS(A) ((((A)&0xFF00)>>8) | (((A)&0x00FF)<<8))
    eh->th_type = NTOHS(eh->th_type);  // 网络字节序转为主机字节序

    // 以太网协议类型
    ui->maclinkType->setText( "0x" +QString::fromStdString( dataToString(eh->th_type,16)));

    // 目标地址 MAC
    memset(buf,0x00,sizeof buf);
#define A(I) eh->dMac[I]
    sprintf(buf," %02X:%02X:%02X:%02X:%02X:%02X ",A(0),A(1),A(2),A(3),A(4),A(5));

    ui->maclinkDes->setText(buf);

    // 源地址 MAC
    memset(buf,0x00,sizeof buf);
#define B(I) eh->sMac[I]
    sprintf(buf," %02X:%02X:%02X:%02X:%02X:%02X ",B(0),B(1),B(2),B(3),B(4),B(5));
    ui->maclinkSrc->setText(buf);
}
void TcpForm::slot_capture()
{
    //  capturePackage();
    std::thread t(&TcpForm::capturePackage,this);
    t.detach();
}

/* Callback function invoked by libpcap for every incoming packet */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    struct tm ltime;
    char timestr[16];
    time_t local_tv_sec;

    /*
     * unused variables
     */
    (VOID)(param);
    (VOID)(pkt_data);

    /* convert the timestamp to readable format */
    local_tv_sec = header->ts.tv_sec;
    localtime_s(&ltime, &local_tv_sec);
    strftime( timestr, sizeof timestr, "%H:%M:%S", &ltime);

     printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);


    ip_header *ih;
    tcp_header *th;
    u_int ip_len;
    u_short sport,dport;

    /* retireve the position of the ip header */
    ih = (ip_header *) (pkt_data +
                        14); //length of ethernet header

    /* retireve the position of the udp header */
    ip_len = (ih->ver_ihl & 0xf) * 4;
    th = (tcp_header *) ((u_char*)ih + ip_len);
    std::cout << " proc tcp package"<< std::endl;

}
void TcpForm::capturePackageLoop()
{

    pcap_t *adhandle;
    char errbuf[255];
    u_int netmask;
    struct bpf_program fcode;
    pcap_if_t *d = SGlobal::getInstace()->getIndexDevcs(SGlobal::getInstace()->g_curCardID,SGlobal::getInstace()->g_alldevs);
    /* Open the device */
    if ( (adhandle= pcap_open(d->name,			// name of the device
                              65536,			// portion of the packet to capture
                              // 65536 guarantees that the whole packet will be captured on all the link layers
                              PCAP_OPENFLAG_PROMISCUOUS, 	// promiscuous mode
                              1000,				// read timeout
                              NULL,				// authentication on the remote machine
                              errbuf			// error buffer
                              ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by Npcap\n", d->name);

        return ;
    }

    printf("\nlistening on %s...\n", d->description);

    // fillter  para
    if(d->addresses != NULL)
        /* Retrieve the mask of the first address of the interface */
        netmask=((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        /* If the interface is without addresses we suppose to be in a C class network */
        netmask=0xffffff;
    char packet_filter[] = "ip and tcp";//"ip and tcp";
    //compile the filter
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) <0 )
    {
        fprintf(stderr,"\nUnable to compile the packet filter. Check the syntax.\n");
        return ;
    }
    //set the filter
    if (pcap_setfilter(adhandle, &fcode)<0)
    {
        fprintf(stderr,"\nError setting the filter.\n");
        return ;
    }
    std::cout<<("\nlistening on ")<< (d->description)<<"..."<<std::endl;
    /* start the capture */
    pcap_loop(adhandle, 0, packet_handler, NULL);
}
void TcpForm::initToolTips()
{
    QString tips= QStringLiteral(
                                 "最大传输单元MTU:以太网和8 0 2 . 3对数据帧的长度都有一个限制，其最大值分别是\n"
                                 "1 5 0 0和1 4 9 2字节。链路层的这个特性称作M T U，最大传输单元\n");
    ui->groupBox->setToolTip(tips);

    tips = QStringLiteral("TCP可靠性："
                          "[1] 应用数据被分割成T C P认为最适合发送的数据块,由 T C P传递给I P的信息单位称为报文段或段（ s e g m e n t）\n"
                          "[2]当T C P发出一个段后，它启动一个定时器，等待目的端确认收到这个报文段。如果不能\n"
                          "及时收到一个确认，将重发这个报文段\n"
                          "[3]当T C P收到发自T C P连接另一端的数据，它将发送一个确认\n"
                          "[4]T C P将保持它首部和数据的检验和\n"
                          "[5]既然T C P报文段作为I P数据报来传输，而 I P数据报的到达可能会失序，因此 T C P报文段\n"
                          "的到达也可能会失序。如果必要， T C P将对收到的数据进行重新排序，将收到的数据以\n"
                          "正确的顺序交给应用层\n"
                          "[6] 既然I P数据报会发生重复，T C P的接收端必须丢弃重复的数据\n"
                          "[7] T C P还能提供流量控制。 T C P连接的每一方都有固定大小的缓冲空间。 T C P的接收端只\n"
                          "允许另一端发送接收端缓冲区所能接纳的数据\n"
                          "序号:用来标识从T C P发端向T C P收端发送的数据字节流,序号是32 bit的无符号数，序号到达2\n"
                          "^32－1后又从0开始\n"
                          "当建立一个新的连接时， S Y N标志变1。序号字段包含由这个主机选择的该连接的初始序\n"
                          "号ISN（Initial Sequence Number）。该主机要发送数据的第一个字节序号为这个 ISN加1，因为\n"
                          "SYN标志消耗了一个序号\n"
                          "U R G 紧急指针（u rgent pointer）有效\n"
                          "A C K 确认序号有效。\n"
                          "P S H 接收方应该尽快将这个报文段交给应用层。\n"
                          "R S T 重建连接。\n"
                          "S Y N 同步序号用来发起一个连接。\n"
                          "F I N 发端完成发送任务。"
                          "T C P的流量控制由连接的每一端通过声明的窗口大小来提供\n"
                          "窗口大小为字节数，起始于确认序号字段指明的值，这个值是接收端正期望接收的字节。窗口大小是一个 16 bit字段，\n"
                          "因而窗口大小最大为 6 5 5 3 5字节\n"
                          "检验和覆盖了整个的T C P报文段：T C P首部和T C P数据。这是一个强制性的字段，一定是\n"
                          "由发端计算和存储，并由收端进行验证"
                          "只有当U R G标志置1时紧急指针才有效\n"
                          "最常见的可选字段是最长报文大小，又称为 MSS (Maximum Segment Size)。每个连接方,M S S选项只能出现在S Y N报文段中\n"
                          "通常都在通信的第一个报文段（为建立连接而设置 S Y N标志的那个段）中指明这个选项。它\n"
                          "指明本端所能接收的最大长度的报文段。"
                          "建立一个连接需要三次握手，而终止一个连接要经过 4次握手。这由T C P的半关闭（h a l f -c l o s e）造成的\n"
                          "收到一个F I N只意味着在这一方向上没有数据流动。一个 T C P连接在收到一个 F I N后仍能发送数据\n"
                          );
    ui->groupBox_2->setToolTip(tips);
}

