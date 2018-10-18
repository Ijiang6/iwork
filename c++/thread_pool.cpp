#include "thread_pool.h"

CThread_Pool::CThread_Pool()
{
}
CThread_Pool::~CThread_Pool()
{
}
CThread_Pool *CThread_Pool::m_pInstance=NULL;
vector<CThread_Task*> CThread_Pool::m_vecTask;
bool CThread_Pool::bDestory = false;
//CMutexConnTool::getInstance()->mutex_conn_init(&m_condition);
pthread_mutex_t CThread_Pool::pmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t CThread_Pool::pcond = PTHREAD_COND_INITIALIZER;
CThread_Pool* CThread_Pool::getInstance()
{
    if(m_pInstance == NULL)
    {
	m_pInstance = new CThread_Pool();
        m_pInstance->setMaxThreadNum(3);
        m_pInstance->CreateThread();
    }
    return m_pInstance;

}
void CThread_Pool::setDestory(bool bTrue)
{
	bDestory=bTrue;
}
void CThread_Pool::setMaxThreadNum(const int iMaxNum)
{
	m_iMaxNum=iMaxNum;
}
void CThread_Pool::CreateThread()
{
    cout<<"create"<<m_iMaxNum<<"thread"<<endl;
	pthread_id = new pthread_t[m_iMaxNum];
	for(int iTrun = 0; iTrun < m_iMaxNum; iTrun++)
	{
		pthread_create(&pthread_id[iTrun], NULL,threadFunc, NULL);
        cout<<"create thread:"<<pthread_id[iTrun]<<endl;
	}
}
void CThread_Pool::addTask(CThread_Task *pTask)
{
//	CMutexConnTool::getInstance()->mutex_conn_lock(&m_condition);
  pthread_mutex_lock(&pmutex);
	m_vecTask.push_back(pTask);
//	CMutexConnTool::getInstance()->mutex_conn_unlock(&m_condition);
    pthread_mutex_unlock(&pmutex);
    pthread_cond_signal(&pcond);
//    CMutexConnTool::getInstance()->mutex_conn_signal(&m_condition);
}
int CThread_Pool::destoryAllThread()
{
	if(bDestory)
		return -1;
	bDestory = true;
    cout<<"destroy all thread"<<endl;
//i//i	CMutexConnTool::getInstance()->mutex_conn_broadcast(&m_condition);
  pthread_cond_broadcast(&pcond);
	for(int i = 0; i < m_iMaxNum; i++)
		pthread_join(pthread_id[i], NULL);
	delete[] pthread_id;
	pthread_id = NULL;
//	CMutexConnTool::getInstance()->mutex_conn_destory(&m_condition);
 pthread_cond_destroy(&pcond);
 pthread_mutex_destroy(&pmutex);
	return 0;
}
void* CThread_Pool::threadFunc(void *args)
{
	pthread_t pid=pthread_self();
	for (;;)
	{
        pthread_mutex_lock(&pmutex);
		while (m_vecTask.size()==0 && !bDestory)
		{
//			CMutexConnTool::getInstance()->mutex_conn_wait(&m_condition);
            pthread_cond_wait(&pcond,&pmutex);
		}
		if (bDestory)
		{
			//CMutexConnTool::getInstance()->mutex_conn_unlock(&m_condition);
            pthread_mutex_unlock(&pmutex);
            pthread_exit(NULL);
		}
//		CMutexConnTool::getInstance()->mutex_conn_lock(&m_condition);
       // pthread_mutex_lock(&pmutex);
		vector<CThread_Task *>::iterator it=m_vecTask.begin();
		CThread_Task *pTask=NULL;
		if (it != m_vecTask.end())
		{
            pTask=*it;
			m_vecTask.erase(it);
		}
        pthread_mutex_unlock(&pmutex);
//		CMutexConnTool::getInstance()->mutex_conn_unlock(&m_condition);
		cout<<"thread ID:"<<pid;
		pTask->run();
	}
}
int CThread_Pool::getTaskSize()
{
    return m_vecTask.size();
}
