#include "SGlobal.h"

SGlobal* SGlobal::pInstance = nullptr;
 SGlobal*  SGlobal::getInstace()
{
    if(pInstance == nullptr)
    {
        pInstance = new SGlobal;
    }
    return pInstance;
 }

 pcap_if_t *SGlobal::getIndexDevcs(int index, pcap_if_t *alldevs)
 {
     int temp =0;
     pcap_if_t *d=alldevs;
     for(; d && temp!= index; d=d->next,temp++);
     return d;
 }

