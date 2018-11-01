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

int main(int argc,char **argv)
{
    int msq_id;
    key_t key;
    struct msg_form msg;

    //get key
    if((key = ftok(MSG_FILE,'z')) <0)
    {
        perror("get key error");
        exit(1);
    }
    else
    {
        printf("key :%d.\n",key);
    }

    if((msq_id = msgget (key ,IPC_CREAT|0777)) == -1)
    {
        perror("msg getkey error");
        exit(1);
    }

    printf( "process ID:%d , msq_id : %d\n",getpid(),msq_id);

    for(; ;)
    {
        msgrcv(msq_id,&msg,256 ,888,0);
        printf("recv msg.text :%s \n,msg.type : %d\n",msg.mchtext, msg.mtype);
        msg.mtype = 999;
        memset(msg.mchtext,0,sizeof(msg.mchtext));
        sprintf(msg.mchtext ,"hello, this is server %d\n",getpid());
        msgsnd(msq_id,&msg,sizeof(msg.mchtext),0);
    }
    return 0;
}
