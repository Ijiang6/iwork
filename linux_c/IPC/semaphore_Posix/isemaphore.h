#ifndef ISEMAPHORE_H
#define ISEMAPHORE_H

#include<semaphore.h>
#include<iostream>
#include<pthread.h>
#include<string>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
using namespace std;
struct Dish
{
    sem_t apple;
    sem_t   pear;
};
Dish dish;
static pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
class producer
{
    public :
        producer(string str);
        ~producer();
    static  void* produce_fruit(void *ags){}
         string m_name;
};
class consumer
{
    public:
        consumer(string str);
        ~consumer();
     static void* eat_fruit(void *ags){}

    string m_name;
};

class father:public producer
{
    public:
        father(string str);
        ~father();
  static  void* produce_fruit(void *ags);
};

class mother :public producer
{
    public:
        mother(string str);
        ~mother();
   static  void* produce_fruit(void *ags);
};

class son:public consumer
{

    public:
        son(string str);
        ~son();
static   void* eat_fruit(void *ags);
};

class daughter:public consumer
{
    public:
        daughter(string str);
        ~daughter();
   static void* eat_fruit(void *ags);
};
#endif








