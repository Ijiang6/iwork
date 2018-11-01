#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char **argv)
{

    int fd=0;
    int n=0;
    int i=0;
    char buf[1024];
    time_t tp;

    printf( "process ID:%d",getpid());

    if((fd = open("fifow",O_WRONLY)) < 0)
    {
        perror("fifow open error");
        exit(1);

    }
    for(int i =0;i<10;i++)
    {

        time(&tp);// system time
        n= sprintf(buf,"process ID:%d,time:%s",getpid(),ctime(&tp));
        printf("msg: %s",buf);
        
        if(write(fd,buf,n+1) <0)
        {
            perror("write file faile");
            exit(1);
        }
        sleep(1);
    }
    close(fd);
    return 0;
}
