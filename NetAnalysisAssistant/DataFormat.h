#ifndef DATAFORMAT_H
#define DATAFORMAT_H
#include <pcap.h>
/* 4 bytes IP address */
typedef struct ip_address{
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
}ip_address;

/* IPv4 header */
typedef struct ip_header{
    u_char	ver_ihl;		// Version (4 bits) + Internet header length (4 bits)
    u_char	tos;			// Type of service
    u_short tlen;			// Total length
    u_short identification; // Identification
    u_short flags_fo;		// Flags (3 bits) + Fragment offset (13 bits)
    u_char	ttl;			// Time to live
    u_char	proto;			// Protocol
    u_short crc;			// Header checksum
    ip_address	saddr;		// Source address
    ip_address	daddr;		// Destination address
    u_int	op_pad;			// Option + Padding
}ip_header;

/* UDP header*/
typedef struct udp_header{
    u_short sport;			// Source port
    u_short dport;			// Destination port
    u_short len;			// Datagram length
    u_short crc;			// Checksum
}udp_header;

// tcp 协议  传输层
struct tcp_header {
    u_short      sport;             // 源端口
    u_short      dport;             // 目的端口
    u_int      seqNum;              // 序列号
    u_int      ackNum;              // 确认号
    u_short      off_res_flag;      // 数据偏移 4  保留位 6  标志位 6
    u_short      winSize;           // 窗口大小
    u_short      checkSum;          // 校验和
    u_short      urgentPoint;       // 紧急指针
};
//数据链路层协议

struct Ethernet_header
{
    u_char  sMac[6];//源地址
    u_char  dMac[6];//目的地址
    u_short th_type;//类型
};

#endif // DATAFORMAT_H
