#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<string.h>
#include<sys/select.h>
#define MAXLINKS 5
using std::cout;
using std::endl;
class tcp_server
{
 public:
    tcp_server();
    ~tcp_server();
    bool create_sock();
    bool sock_addr_init(int iport);
    bool sock_bind();
    bool s_listen(int imax_links);
    bool s_accept();
    bool data_recv(int icon);
    bool date_write(int icon);
    void init_select();
    void selectIO();
    int update_maxfd();
    void add_newclient(int clietn_conn);
 private:
    struct sockaddr_in s_addr;
    int isockfd;
    int iconn;
    int maxfd;
    int ilisten;
    int client[MAXLINKS];
    char buf[1024];
    fd_set readset;
    fd_set allset;
};
#endif
