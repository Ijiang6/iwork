#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <pthread.h>
#include <iostream>
#include <string>
#include <vector>
#include "thread_task.h"
#include "mutex_conn_tool.h"
using namespace std;
class CThread_Task;
class CThread_Pool
{
public:
	CThread_Pool();
	~CThread_Pool();
	void setMaxThreadNum(const int iMaxNum);
	static void* threadFunc(void *args);
	void CreateThread();
	void addTask(CThread_Task *pTask);
    int destoryAllThread();
	void setDestory(bool bTrue);
	int  getTaskSize();
private:
	int m_iMaxNum;
    static bool bDestory;
      pthread_t *pthread_id;
	static vector<CThread_Task*> m_vecTask;
	static mutex_conn m_condition;
    static pthread_mutex_t pmutex;
    static pthread_cond_t pcond;
};
#endif 
