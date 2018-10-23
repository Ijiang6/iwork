#ifndef FILE_TASK_H
#define FILE_TASK_H
#include"thread_task.h"
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <assert.h>
using namespace std;
class file_task:public CThread_Task
{
public:
    file_task();
    ~file_task();
    void setInFile(const string & strPath);
    void setOutFIle(const string & strPath);
    void readFile();
    void writefile();	
    void setWriteFile(const vector<string> & vecFile);
    void setRun(bool bread);
    virtual void* run();
    const string popOnestr();
private:
    string m_strInFile;
    string m_strOutFile;
    ifstream m_Instream;
    ofstream m_Outstream;
    char buf[1024];
    bool m_bFinsh;
    bool m_bread;
    vector<string> vfile;

};
#endif
