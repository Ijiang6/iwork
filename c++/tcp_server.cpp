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
 FD_ZERO(&writeset);
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
int tcp_server::byte_to_int(const char *pbuf)
{
   return  cplusplusTool::byte_to_int(pbuf);
}
char * tcp_server::int_to_byte(int iNum)
{
 return cplusplusTool::int_to_byte(iNum);
}
void tcp_server::insertOneLineStr(const string & strName,const string & strLine)
{

    map<string,vector<string>>::iterator it=m_mapfile.find(strName);
    if(it != m_mapfile.end())
    {
	it->second.push_back(strLine);
    }
    else
    {
	vector<string> vecfile;
	vecfile.push_back(strLine);
	m_mapfile[strName]=vecfile;
    }


}
void tcp_server::saveFile(const string & strFile)
{

    map<string,vector<string>>::iterator it=m_mapfile.find(strFile);
    if(it != m_mapfile.end())
    {
	 m_file_task.setOutFIle(strFile);
	m_file_task.setRun(false);
        CThread_Pool::getInstance()->addTask(&m_file_task);
    }
}
bool tcp_server::data_recv(int icon)
{   icon=iconn;
    memset(buf,0,sizeof(buf)); 
    read(icon,buf,sizeof(buf));
    cout<<"recv:"<<buf<<endl;
    //$+4+type+4+name+4+data
    //@+4+type+4+name+4(file_size)
    assert(buf[0]=='$'|| buf[0]=='@');
    char size[4];
    bzero(size,4);
    char *pData=buf;
    pData++;
    //file_type_size
    memcpy(size,pData,4);
    int isize=byte_to_int(size);
    char temp[1024];
    bzero(temp,1024);
    pData+=4;
    //file_type
    memcpy(temp,pData,isize);
    string file_type=temp;
    pData+=isize;
    bzero(size,4);
    //file_name_size
    memcpy(size,pData,4);
    isize=byte_to_int(size);
    bzero(temp,1024);
    //file_name
    pData+=4;
    memcpy(temp,pData,isize);
    string file_name=temp;
    pData+=isize;
    //file_data_size
    bzero(size,4);
    memcpy(size,pData,4);
    isize=byte_to_int(size);
    string strdata;
    string strfile="./temp/"+file_name+"."+file_type;
    if(strdata == "$#$")
    {
    //one file recv finsh
	saveFile(strfile);    
    }
    if(buf[0] != '@')
    {
    bzero(temp,1024);
    pData+=4;
    memcpy(temp,pData,isize);
     strdata=temp;
    }
    cout<<"file_type->"<<file_type<<endl<<"file_name->"<<file_name<<endl<<"datasize->"<<isize<<endl<<"data->"<<strdata<<endl;
    //save one line  data(temp)
    insertOneLineStr(strfile,strdata);
}
bool tcp_server::date_write(int icon,const string &strType,const string & strName,const string &strData)
{
    //$+4byte+strType+4byte+strNmae+4byte+strData
    string strPacket;
    icon=iconn;
    
    char chs='$';
    char *pchsSize=NULL;
    strPacket.append(&chs);
    
    pchsSize=int_to_byte(strType.size());
    strPacket.append(pchsSize,4);
    strPacket.append(strType);
    
    pchsSize=int_to_byte(strName.size());
    strPacket.append(pchsSize,4);
    strPacket.append(strName);

    pchsSize=int_to_byte(strData.size());
    strPacket.append(pchsSize,4);
    strPacket.append(strData);

    write(icon,strPacket.c_str(),strPacket.size());
    return true;
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
    FD_ZERO(&writeset);
    //readset=allset;
    memcpy(&readset,&allset,sizeof(allset));
    writeset=readset;
    maxfd=update_maxfd();
    cout<<"maxfd:"<<maxfd<<"isockfd:"<<isockfd<<endl;
  //  FD_SET(isockfd,&readset);
    int ireadynum=select(maxfd+1,&readset,&writeset,NULL,&timer);
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
	} 
	if(FD_ISSET(icon,&writeset))
	{
	    string strLine=pfile->popOnestr();
	  date_write(icon,fileType,fileName,strLine);
	}
    }
 }



}
void tcp_server::readfiletest()
{
    pfile=new file_task();
    pfile->setInFile("./demo.txt");
    pfile->setRun(true);
    fileType="txt";
    fileName="demo";
    CThread_Pool::getInstance()->addTask(pfile);

}
int  main(int argc ,char*argv[])
{
   tcp_server server;
   server.readfiletest();
   server.create_sock();
   server.sock_addr_init(8989);
   server.sock_bind();
   server.s_listen(MAXLINKS);
    server.init_select();
    server.s_accept();
    server.data_recv(1);
   // server.date_write(1);
   // server.selectIO();
return 0;

}
