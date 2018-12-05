#include"read_write.h"
using namespace std;

rdlock::rdlock(int inum)
{
    iNum=inum;
}

rdlock::~rdlock()
{


}

void* rdlock::pthread_fun(void *ags)
{
    while(1)
    {
    pthread_rwlock_rdlock(&rwlock); 
    cout<<"read thread----"<<iNum<<"----count:"<<(var.count)<<endl;
    pthread_rwlock_unlock(&rwlock);
    sleep(1);
    }
}

wrlock::wrlock(int inum)
{
    iNum=inum;
}
wrlock::~wrlock()
{
}

void* wrlock::pthread_fun(void *ags)
{
    while(1)
    {
        pthread_rwlock_wrlock(&rwlock);
    if(iNum<(var.ipriority))
    {
        pthread_rwlock_unlock(&rwlock);
        var.ipriority=iNum;
        continue;
    }
    else
    {
        var.ipriority=iNum;
        var.count++;
        cout<<"write thread####"<<iNum<<"#####"<<endl;
    }
    pthread_rwlock_unlock(&rwlock);
    sleep(2);
    }
}

int main(int argc  ,char *argv[])
{

    pthread_t  thread[6];
    rdlock *rd;
    wrlock *wr;
    int ires;
    for(int iTrun=0; iTrun<3;iTrun++)
    {
        //read thread
        rd=new rdlock(iTrun);
        ires=pthread_create(&thread[iTrun],NULL, rd->pthread_fun,NULL);
        if(ires !=0)
        {
            cout<<"create read--"<<iTrun<<"--thread error"<<endl; 
        }
        else
        {
            cout<<"create read--"<<iTrun<<"--thread ok"<<endl; 
        }

        // write thread
        wr=new wrlock(iTrun+3);
        ires=pthread_create(&thread[iTrun+3],NULL, wr->pthread_fun,NULL);

        if(ires !=0)
        {
            cout<<"create write--"<<iTrun+3<<"--thread error"<<endl; 
        }
        else
        {
            cout<<"create write--"<<iTrun+3<<"--thread ok"<<endl; 
        }
    }
sleep(60);


}

