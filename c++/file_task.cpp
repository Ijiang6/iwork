#include"file_task.h"
file_task::file_task():CThread_Task()
{

}
file_task::~file_task()
{


}
void file_task::setInFile(const string &strPath)
{
    m_strInFile=strPath;
}
void file_task::setOutFIle(const string & strPath)
{
    m_strOutFile=strPath;
}
void file_task::readFile()
{
    vector<string> vfile;
    string strTemp;
    m_Instream.open(m_strInFile);
   if(!m_Instream.is_open())
    {
	cout<<"open readfile failed"<<endl;
    return ;
    }
    while(!m_Instream.eof())
   {
       m_Instream.read(buf,900);
       strTemp.append(buf,strlen(buf));
       vfile.push_back(strTemp);
       strTemp.clear();
   }
    m_bFinsh=true;
    cout<<"fileLines:"<<vfile.size()<<endl;
    m_Instream.close();
}
void file_task::writefile()
{
  m_Outstream.open(m_strOutFile,ios::app);
  if(!m_Outstream.is_open())
  {
   cout<<"open writefile faield"<<endl;
   return;
  }
  assert(vfile.size()>0);
  vector<string>::iterator it=vfile.begin();
  for(;it != vfile.end();it++)
    {
    m_Outstream<<*it;
    m_Outstream.flush();
    }
  m_Outstream.close();
}
const string file_task::popOnestr()
{
    string str;
    vector<string>::iterator it=vfile.begin();
    cout<<"cfile size:"<<vfile.size();
    if(it != vfile.end())
    {
        str=*it;
        vfile.erase(it);
    }
    return str;
}
void file_task::setWriteFile(const vector<string> & vecFile)
{
    vfile.clear();
    if(!vecFile.empty())
    {
	vfile=vecFile;
    }


}
void file_task::setRun(bool bread)
{
    m_bread=bread;
}
void* file_task::run()
{
    if(m_bread)
    {
        readFile();
    }
    else
    {
        writefile();
    }
    return (void *)0;
}
