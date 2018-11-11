#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<string.h>
#include<assert.h>
#include"c++Tool.h"
#include<sys/select.h>
#include"thread_task.h"
#include"file_task.h"
#include"thread_pool.h"
#include<map>
#include<vector>
#include<signal.h>
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
    bool date_write(int icon,const string &strType,const string & strName,const string &strData);
    void init_select();
    void selectIO();
    int update_maxfd();
    int byte_to_int(const char *pbuf);
    char * int_to_byte(int iNum);
    void add_newclient(int clietn_conn);
    void readfiletest();
    void insertOneLineStr(const string & strName,const string &strLine);
    void saveFile(const string & strFile);
 private:
    struct sockaddr_in s_addr;
    int isockfd;
    int iconn;
    int maxfd;
    int ilisten;
    int client[MAXLINKS];
    char buf[1024];
    map<string,vector<string>>m_mapfile;
    fd_set readset;
    fd_set allset;
    fd_set writeset;
    file_task m_file_task;
    string fileType;
    string fileName;
    file_task *pfile;
};
#endif
