#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/msg.h>

#define MSG_FILE "passwd"

struct msg_form
{
    long mtype;
    char mchtext[256];
};
int main(int argc ,char ** argv)
{

    int msqid;
    key_t key;
    struct msg_form msg;

    //get key
    if((key = ftok(MSG_FILE,'z'))<0)
    {
        perror("get key error");
        exit(1);
    }
    else
    {
        printf("msq client key:%d\n",key);

    }

    if((msqid = msgget(key ,IPC_CREAT|0777)) <0)
            {
            perror("msgget error");
            exit(1);
            }
    printf("msqid:%d\n, PID=%d\n",msqid,getpid());

    msg.mtype=888;
    sprintf(msg.mchtext,"hello, this is client %d\n",getpid());
    msgsnd(msqid, &msg,sizeof(msg.mchtext),0);
    memset(msg.mchtext,0,sizeof(msg.mchtext));

    msgrcv(msqid,&msg,256,999,0);
    printf("client:recv msg.mchtext:%s\n,msg.mtype:%d\n",msg.mchtext,msg.mtype);
    return 0;
}
