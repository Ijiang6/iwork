#include"thread_pool.h"
#include "stdlib.h"
#include "file_task.h"
#include<unistd.h>
int main() {
    file_task fileobj;
    CThread_Task taskObj;
    CThread_Pool threadpool;  //线程池大小为5
    threadpool.setMaxThreadNum(5);
    threadpool.CreateThread(); 
    for(int i = 0; i < 10; i++)
        threadpool.addTask(&taskObj);
    
    while(1) {
        printf("There are still %d tasks need to handle\n", threadpool.getTaskSize());
        //任务队列已没有任务了
        if(threadpool.getTaskSize()==0) {
            //清除线程池
            if(threadpool.destoryAllThread() == -1) {
                printf("Thread pool clear, exit.\n");
                exit(0);
            }
        }
        sleep(2);
        printf("2 seconds later...\n");
    }   
    return 0;
}
