#include"mutex_conn_tool.h"
CMutexConnTool::CMutexConnTool()
{

}

CMutexConnTool::~CMutexConnTool()
{

}

CMutexConnTool* CMutexConnTool::m_pInstance = NULL;

CMutexConnTool* CMutexConnTool::getInstance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new CMutexConnTool();
	}
	return m_pInstance;
}

int CMutexConnTool::mutex_conn_init(mutex_conn *pCondition)
{
	int imutex,iconn;
	imutex= pthread_mutex_init(&pCondition->pmutex, NULL);
	iconn=pthread_cond_init(&pCondition->pcond,NULL);
	if (imutex==0 && iconn==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int CMutexConnTool::mutex_conn_lock(mutex_conn *pCondition)
{
	 return pthread_mutex_lock(&pCondition->pmutex);
}
int CMutexConnTool::mutex_conn_unlock(mutex_conn *pCondition)
{
	return pthread_mutex_unlock(&pCondition->pmutex);
}
int CMutexConnTool::mutex_conn_wait(mutex_conn *pCondition)
{
	 return pthread_cond_wait(&pCondition->pcond, &pCondition->pmutex);
}
int CMutexConnTool::mutex_conn_timewait(mutex_conn *pCondition ,const struct timespec *abstime)
{
	return pthread_cond_timedwait(&pCondition->pcond, &pCondition->pmutex, abstime);
}
int CMutexConnTool::mutex_conn_signal(mutex_conn *pCondition)
{
	return pthread_cond_signal(&pCondition->pcond);
}
int CMutexConnTool::mutex_conn_broadcast(mutex_conn *pCondition)
{
	 return pthread_cond_broadcast(&pCondition->pcond);
}
int CMutexConnTool::mutex_conn_destory(mutex_conn *pCondition)
{
	int status;
	if((status = pthread_mutex_destroy(&pCondition->pmutex)))
		{
			return status;
		}
	if((status = pthread_cond_destroy(&pCondition->pcond)))
		{
			return status;
		}
	return 0;
}
