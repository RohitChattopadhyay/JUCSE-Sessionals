#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include<time.h> 

typedef struct 
{
    int status; // 0 busy, 1 free
    int writeStatus; // 0 no content, 1 has content
    int payload,readerCount,writerCount;
} BUFFER;

BUFFER init_buffer()
{
    BUFFER a;
    a.status = 1;
    a.writeStatus = 0;
    a.readerCount = 0;
    a.writerCount = 0;
    return a;
}

static BUFFER * buf;  
void createProcess() 
{   
    buf = mmap(NULL, sizeof *buf, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);    
    *buf = init_buffer();
    int producer_branch, consumer_branch, parent, child, r , w ;
    w = 1;
    printf("Enter number of writers:\t");
    scanf("%d",&w);
    printf("Enter number of readers:\t");
    scanf("%d",&r);
    if(w*r==0){
        printf("\nError: They cannot be zero\n");
        exit(0);
    }
    child = fork();
    if(child==0){
        //Writer branch (child)
        for((*buf).writerCount = 0; (*buf).writerCount < w; ++(*buf).writerCount){
            if(fork()==0){
                int loopCounter = 0;
                while(loopCounter++<10){
                    sleep(2);
                    srand(time(0));
                    while((*buf).status != 1); // Hold till busy
                    (*buf).status = 0; //Make busy
                    int temp = rand();
                    (*buf).payload = temp;
                    printf("[W%d]: Wrote\t%d\n",getpid(),temp);
                    (*buf).writeStatus = 1;
                    (*buf).status = 1; //Make idle
                }
                (*buf).writeStatus = 0;
                exit(0);
            }
        }
    }
    else{
        //Reader branch (parent)
        while((*buf).writeStatus != 1); // Hold till written
        for((*buf).readerCount = 0; (*buf).readerCount < r; (*buf).readerCount++){
            if(fork()==0){
                while((*buf).writeStatus==1){
                    sleep(1);
                    if((*buf).status==1)
                        printf("[R%d]: Read\t%d\n",getpid(),(*buf).payload);
                }
                exit(0);
            }
        }
    }
    munmap(buf, sizeof *buf);
}
int main() 
{ 
    createProcess(); 
    return 0; 
}
