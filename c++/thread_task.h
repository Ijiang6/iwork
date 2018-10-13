#ifndef THREAD_TASK_H
#define THREAD_TASK_H
#include <iostream>
using namespace std;
class CThread_Task
{
public:
	 CThread_Task();
	virtual ~CThread_Task();
	virtual void * run();
private:
	
};
#endif 
