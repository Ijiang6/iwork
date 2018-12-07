#include"isemaphore.h"
#include<stdio.h>
#include<unistd.h>
using namespace std;

producer::producer(string str)
{
 m_name=str;
 string strapple="apple";
 string strpear="pear";

 dish.apple=*(sem_open(strapple.c_str(),O_RDWR|O_CREAT,0644,0));
 dish.pear=*(sem_open(strpear.c_str(),O_RDWR|O_CREAT,0644,0));
}

producer::~producer()
{
    pthread_mutex_destroy(&mutex);

}



father::father(string str):producer(str)
{
   
}
father::~father()
{

}

void* father::produce_fruit(void *ags)
{
   cout<<"FATHER"<<endl;
    while(1)
    {
    pthread_mutex_lock(&mutex);
    cout<<"father ->apple"<<endl;
    sem_post(&dish.apple);
    pthread_mutex_unlock(&mutex);
    }
}
mother::mother(string str):producer(str)
{

}
mother::~mother()
{
}

void* mother::produce_fruit(void *ags)
{
    cout<<"MOTHER"<<endl;
while(1)
{
    pthread_mutex_lock(&mutex);
    cout<<"mother ->pear"<<endl;
    sem_post(&dish.pear);
    pthread_mutex_unlock(&mutex);
}
}
consumer::consumer(string str)
{

 m_name=str;
 string strapple="apple";
 string strpear="pear";

 dish.apple=*(sem_open(strapple.c_str(),O_RDWR|O_CREAT,0644,0));
 dish.pear=*(sem_open(strpear.c_str(),O_RDWR|O_CREAT,0644,0));
}
consumer::~consumer()
{

    pthread_mutex_destroy(&mutex);
}
son::son(string str):consumer(str)
{
}

son::~son()
{
}

void* son::eat_fruit(void *ags)
{
   cout<<"SON"<<endl;
    while(1)
    {
    pthread_mutex_lock(&mutex);
    sem_wait(&dish.apple);
    cout<<"son ->apple"<<endl;
    pthread_mutex_unlock(&mutex);
    }
}
daughter::daughter(string str):consumer(str)
{

}

daughter::~daughter()
{
}

void* daughter::eat_fruit(void *ags)
{
   cout<<"DAUGHTER"<<endl;
while(1)
{
    pthread_mutex_lock(&mutex);
    sem_wait(&dish.pear);
    cout<<"daughter ->pear"<<endl;
    pthread_mutex_unlock(&mutex);
}
}
int main(int argc,char *argv[])
{

 father *pdad=new father("father");
 mother *pmom =new mother("mother");
 son *pboy=new son("son");
 daughter *pgirl=new daughter("daughter");
 pthread_t thread[4];   
    pthread_create(&thread[0],NULL,pdad->produce_fruit,NULL);
    pthread_create(&thread[1],NULL,pmom->produce_fruit,NULL);
    pthread_create(&thread[2],NULL,pboy->eat_fruit,NULL);
    pthread_create(&thread[3],NULL,pgirl->eat_fruit,NULL);
 
 sleep(120);
 delete pdad;
 delete pmom;
 delete pboy;
 delete pgirl;



}
