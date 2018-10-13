#include"file_task.h"
file_task::file_task():CThread_Task()
{
    memset(buf,0,sizeof(buf));

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
   while(getline(m_Instream,strTemp))
   {
       vfile.push_back(strTemp);
   }
    cout<<"fileLines:"<<vfile.size()<<endl;
    m_Instream.close();
}
void file_task::writefile()
{
  m_Outstream.open(m_strOutFile);
  if(!m_Outstream.is_open())
  {
   cout<<"open writefile faield"<<endl;
   return;
  }
  m_Outstream<<buf;
  m_Outstream.flush();
  m_Outstream.close();
}
