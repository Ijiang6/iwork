#include"tcp_server.h"
tcp_server::tcp_server()
{
    maxfd=0;
}
tcp_server::~tcp_server()
{

}
void tcp_server::init_select()
{
 FD_ZERO(&readset);
 FD_ZERO(&allset);
 for(int iTrun=0;iTrun<MAXLINKS;iTrun++)
 {
     client[iTrun]=-1;
 }
}
bool tcp_server::sock_addr_init(int iport)
{
    bool bok=false;
    s_addr.sin_family=AF_INET;
    s_addr.sin_port=htons(iport);
    s_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    
    if(sizeof(s_addr)>0)
    {
     bok = true;
    }
    return bok;
}
bool tcp_server::create_sock()
{
    bool bok=false;
  isockfd = socket(AF_INET,SOCK_STREAM,0);
  if(isockfd>0)
    {
	bok=true;
    }
  return bok;
}
bool tcp_server::sock_bind()
{
    bool bok = false;
    socklen_t s_len;
    s_len=sizeof(s_addr);
   int ibind= bind(isockfd,(struct sockaddr *)&s_addr,s_len);
 if(ibind>0)
 {
     bok = true;
 }
 return bok;
}
bool tcp_server::s_listen(int imax_links)
{
     ilisten=listen(isockfd,imax_links);
   if(ilisten<0)
    {
     return false;
    }
    return true;
}
bool tcp_server::s_accept()
{
    struct sockaddr_in c_addr;
    socklen_t c_len=sizeof(c_addr);
    iconn =accept(isockfd,(struct sockaddr *)&c_addr,&c_len);
    if(iconn>0)
    {   
	cout<<"receive new connection"<<endl;
	return true;

    }
    else
    {
    return false;
    }

}
bool tcp_server::data_recv(int icon)
{   memset(buf,0,sizeof(buf)); 
    read(icon,buf,sizeof(buf));
    cout<<buf<<endl;
}
bool tcp_server::date_write(int icon)
{

    write(icon,buf,sizeof(buf));

}
int tcp_server::update_maxfd()
{
    int maxtemp=0;
    for(int iTrun=0;iTrun<sizeof(allset);iTrun++)
    {
	if(FD_ISSET(iTrun,&allset))
	{
	    if(iTrun>maxtemp)
	    {
	    maxtemp=iTrun;
	    }
	}
    }
    if(maxtemp > MAXLINKS)
    {
    cout<<"beyond max links,no recv new links"<<endl;
    FD_CLR(isockfd,&allset); 
    }
    return maxtemp;
}
void tcp_server::add_newclient(int clietn_conn)
{
      for(int iTrun = 0;iTrun < MAXLINKS; iTrun++)
      {
        if(client[iTrun]<0)
	{
	    client[iTrun] = clietn_conn;
	}
      }
}
void tcp_server::selectIO()
{
    if(ilisten != 0)
    {
	cout<<"listen num:"<<ilisten;
    return ;
    }
 FD_SET(isockfd,&allset);
 timeval timer;
 timer.tv_sec=10;
 timer.tv_usec=0;
 
 while(1)
 {
    FD_ZERO(&readset);
    //readset=allset;
    memcpy(&readset,&allset,sizeof(allset));
    maxfd=update_maxfd();
    cout<<"maxfd:"<<maxfd<<"isockfd:"<<isockfd<<endl;
  //  FD_SET(isockfd,&readset);
    int ireadynum=select(maxfd+1,&readset,NULL,NULL,&timer);
    cout<<"ireadnum:"<<ireadynum<<endl;
    if(ireadynum < 0 || ireadynum == 0 )
    {
	cout<<"no fd ready"<<endl;
	continue;
    } 
    if(FD_ISSET(isockfd,&readset))
    {
	s_accept();
	add_newclient(iconn);
	FD_SET(iconn,&allset);
	FD_CLR(isockfd,&allset);
    }   
    for(int iTrun =0 ;iTrun <MAXLINKS; iTrun++)
    {
	int icon=client[iTrun];
	if(icon < 0)
	{
	 continue;
	}
	if(FD_ISSET(icon,&readset))
	{
	    data_recv(icon);
	    date_write(icon);
	} 
    }
 }



}
int  main(int argc ,char*argv[])
{
   tcp_server server;
   server.create_sock();
   server.sock_addr_init(8989);
   server.sock_bind();
   server.s_listen(MAXLINKS);
    server.init_select();
    server.selectIO();
return 0;

}
