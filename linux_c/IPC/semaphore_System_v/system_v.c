#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
//init 
int sem_init(int sem_id, int value)
{
    union semun tmp;
    tmp.val=value;
    int ires=0;
    if(semctl(sem_id,0,SETVAL,tmp) == -1)
    {
        perror("error  semphore init");
        ires=-1;
    }
    return ires;
}

// p  -1
int sem_p(int sem_id)
{
    struct sembuf smbuf;
    smbuf.sem_num=0;
    smbuf.sem_op=-1;//p
    smbuf.sem_flg = SEM_UNDO;
    int ires=0;
    ires=semop(sem_id,&smbuf,1);
    if(ires == -1)
    {
        perror("error semphore p");
    }
    return ires;
}
// v +1
int sem_v(int sem_id)
{
    struct sembuf smbuf;
    smbuf.sem_num=0;
    smbuf.sem_op=1;//v
    smbuf.sem_flg = SEM_UNDO;
    int ires=0;
    ires=semop(sem_id,&smbuf,1);
    if(ires == -1)
    {
        perror("error semphore p");
    }
    return ires;
}
// delete
int sem_del(int sem_id)
{
    union semun tmp;
    int ires=0;
    ires=semctl(sem_id,0,IPC_RMID,tmp);
    if(ires == -1)
    {
        perror("error semaphore del");
    }
    return ires;
}


int main(int argc ,char *argv[])
{

    int sem_id;
    key_t key;
    pid_t pid;
    // get key

    key=ftok(".",6);
    if(key<0)
    {
        perror("error semophore key");
        exit(1);
    }
    sem_id=semget(key,1,IPC_CREAT|0777);
    if(sem_id == -1)
    {
        perror("error semaphore semget");
        exit(1);
    }

    //init 
    sem_init(sem_id,0);
    pid=fork();
    if(pid== -1)
    {
        perror("error fork");
    }
    else if(pid ==0)
    {
        //child process
        sleep(2);
        printf("child process@pid=%d\n",getpid());
        sem_v(sem_id);
    }
    else
    {
        //father process
        sem_p(sem_id);
        printf("father process@pid=%d\n",getpid());
        //sem_v(sem_id);
        sem_del(sem_id);

    }
    return 0;
}





