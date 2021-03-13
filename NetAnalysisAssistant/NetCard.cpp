#include "NetCard.h"
#include <tchar.h>
#include"SGlobal.h"
char *iptos(u_long in);
char* ip6tos(struct sockaddr *sockaddr, char *address, int addrlen);
bool NetCard::LoadNpcapDlls()
{
    _TCHAR npcap_dir[512];
    UINT len;
    len = GetSystemDirectory(npcap_dir, 480);
    if (!len) {
        fprintf(stderr, "Error in GetSystemDirectory: %x", GetLastError());
        return false;
    }
    _tcscat_s(npcap_dir, 512, _T("\\Npcap"));
    if (SetDllDirectory(npcap_dir) == 0) {
        fprintf(stderr, "Error in SetDllDirectory: %x", GetLastError());
        return false;
    }
    return true;
}

QString NetCard::getAllInformation(pcap_if_t *d)
{
    QString str;
    if(d != nullptr)
    {   pcap_addr_t *a;
        char ip6str[128];

         /* Name */
        str +=d->name;

         /* Description */
         if (d->description)
           str +="#"+QString("%1").arg(d->description);
         else
             str +="#";

         /* Loopback Address*/
         str +=(d->flags & PCAP_IF_LOOPBACK)?"#yes":"#no";

         /* IP addresses */
         for(a=d->addresses;a;a=a->next) {


           switch(a->addr->sa_family)
           {
             case AF_INET:
                str +=QString("#AF_INET(%1)").arg(a->addr->sa_family);
               if (a->addr)
                 str +=QString("#%1").arg(iptos(((struct sockaddr_in *)a->addr)->sin_addr.s_addr));
               else
                   str +="#";
               if (a->netmask)
                 str +=QString("#%1").arg(iptos(((struct sockaddr_in *)a->netmask)->sin_addr.s_addr));
               else
                   str +="#";
               if (a->broadaddr)
                 str +=QString("#%1").arg(iptos(((struct sockaddr_in *)a->broadaddr)->sin_addr.s_addr));
               else
                   str +="#";
               if (a->dstaddr)
                 str +=QString("#%1").arg(iptos(((struct sockaddr_in *)a->dstaddr)->sin_addr.s_addr));
               else
                   str +="#";
               break;

//             case AF_INET6:
//                 str +=QString("#AF_INET6(%1)").arg(a->addr->sa_family);
//               if (a->addr)
//                 str +=QString("#%1").arg(ip6tos(a->addr, ip6str, sizeof(ip6str)));
//               else
//                   str +="#";
              break;

             default:
               printf("\tAddress Family Name: Unknown\n");
               break;
           }
         }


    }

       return  str;
}

NetCard::NetCard(QObject *parent) : QObject(parent)
{
    updateCardmsg();
}

QStringList   NetCard::updateCardmsg()
{
    QStringList list ;
    pcap_if_t *alldevs;
        pcap_if_t *d;
        int i=0;
        char errbuf[PCAP_ERRBUF_SIZE];
        /* Load Npcap and its functions. */
        if (!LoadNpcapDlls())
        {
            emit sig_dispalyMsg("Couldn't load Npcap");
           return list;
        }
        /* Retrieve the device list */
        if(pcap_findalldevs(&alldevs, errbuf) == -1)
        {
            emit sig_dispalyMsg("Error in pcap_findalldevs:"+QString(errbuf));
          return list;
        }
        /* Print the list */
        for(d=alldevs; d; d=d->next)
        {
           QString  str = getAllInformation(d);
           list.append(str);
        }
        /* At this point, we don't need any more the device list. Free it */
        SGlobal::getInstace()->g_alldevs = alldevs;
     //   pcap_freealldevs(alldevs);
        return  list;
}
/* From tcptraceroute, convert a numeric IP address to a string */
#define IPTOSBUFFERS	12
char *iptos(u_long in)
{
    static char output[IPTOSBUFFERS][3*4+3+1];
    static short which;
    u_char *p;

    p = (u_char *)&in;
    which = (which + 1 == IPTOSBUFFERS ? 0 : which + 1);
    sprintf(output[which], "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
    return output[which];
}

#ifndef __MINGW32__ /* Cygnus doesn't have IPv6 */
char* ip6tos(struct sockaddr *sockaddr, char *address, int addrlen)
{
    socklen_t sockaddrlen;

    #ifdef _WIN32
    sockaddrlen = sizeof(struct sockaddr_in6);
    #else
    sockaddrlen = sizeof(struct sockaddr_storage);
    #endif


//    if(getnameinfo(sockaddr,
//        sockaddrlen,
//        address,
//        addrlen,
//        NULL,
//        0,
//        NI_NUMERICHOST) != 0) address = NULL;

    return address;
}
#endif /* __MINGW32__ */
