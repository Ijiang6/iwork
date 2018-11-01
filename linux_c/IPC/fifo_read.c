#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc ,char **argv)
{
    int fd;
    int len;
    char buf[1024];
        if(mkfifo("fifow",0666),0 && errno != EEXIST)
        {   
            perror("crate fifow error");

        }
        if((fd = open("fifow",O_RDONLY))<0)
        {
            perror("open fifo error");
            exit(1);
        }
        while((len= read(fd,buf,1024))>0)
        {
            printf("Read msg:%s",buf);
        }
        close(fd);
        return 0;
}



