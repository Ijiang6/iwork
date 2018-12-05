#ifndef READ_WRITE_LOCK_H
#define READ_WRITE_LOCK_H

#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>

static pthread_rwlock_t rwlock=PTHREAD_RWLOCK_INITIALIZER;
typedef  struct 
{
  int count;
  int ipriority;
}sVar;

 sVar var;
class rdlock
{
    public:
        rdlock(int inum);
        ~rdlock();
 static       void* pthread_fun(void *ags);

static int iNum;
    
};
int rdlock::iNum=0;
class wrlock
{
    public:
        wrlock(int inum);
        ~wrlock();
static   void* pthread_fun(void *ags);
static    int iNum;
};

int wrlock::iNum=0;



#endif

