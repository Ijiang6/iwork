#ifndef _MUTEX_CONN_TOOL_H_
#define _MUTEX_CONN_TOOL_H_
#include <pthread.h>
typedef struct  mutex_conn
{
	pthread_mutex_t pmutex;
	pthread_cond_t pcond;
}s_cond;

class CMutexConnTool
{
public:
	CMutexConnTool();
	virtual ~CMutexConnTool();
	static CMutexConnTool* getInstance();
	int mutex_conn_init(mutex_conn *pCondition);
	int	mutex_conn_lock(mutex_conn *pCondition);
	int	mutex_conn_unlock(mutex_conn *pCondition);
	int mutex_conn_wait(mutex_conn *pCondition);
	int mutex_conn_timewait(mutex_conn *pCondition ,const struct timespec *abstime);
	int mutex_conn_signal(mutex_conn *pCondition);
	int mutex_conn_broadcast(mutex_conn *pCondition);
	int mutex_conn_destory(mutex_conn *pCondition);
private:
		//µ¥Àý
	static CMutexConnTool *m_pInstance;
};
#endif
