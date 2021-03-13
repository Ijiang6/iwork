#ifndef SGLOBAL_H
#define SGLOBAL_H
#include"pcap.h"
#include<QString>
class SGlobal
{

public:
    pcap_if_t *g_alldevs;
    int g_curCardID;
    QString g_strFiltter;
    bool g_break;
    static SGlobal* getInstace();
    static pcap_if_t* getIndexDevcs(int index ,pcap_if_t * alldevs);
private:
    static SGlobal* pInstance ;
};

#endif // SGLOBAL_H
