#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include<time.h> 

typedef struct 
{
    int consumed,produced;
    int items[25][3];
    int TOTAL;
} BUFFER;

BUFFER init_buffer()
{
    BUFFER a;
    a.consumed = 0;
    a.produced = 0;
    a.TOTAL = 0;
    for(int i = 0; i < 25 ; i++)
      for(int j = 0; j < 3 ; j++)
        a.items[i][j] = 0;      
    return a;
}

static BUFFER * buf;  
void createProcess() 
{   
    buf = mmap(NULL, sizeof *buf, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *buf = init_buffer();
    int producer_branch, consumer_branch, parent, child, p , c ;
    printf("Enter number of producers:\t");
    scanf("%d",&p);
    printf("Enter number of consumers:\t");
    scanf("%d",&c);
    if(p*c==0){
        printf("\nError: They cannot be zero\n");
        exit(0);
    }
    child = fork();
    if(child==0){
        for(int i = 0,j=0; i < p; i++) {
            producer_branch = fork();
            if(producer_branch < 0) {
                printf("Error");                
                exit(1);
            } else if (producer_branch == 0) {
                //Produce
                if((*buf).produced>25)
                    printf("Buffer exceeded\n");
                else{
                    int ti,trand;
                    srand(time(0)); 
                    trand = rand();
                    for(ti = trand; ti < 25+trand; ti++)
                        if((*buf).items[ti%25][1]==0){       
                            ti = ti%25;
                            (*buf).items[ti][1] = 1; //produced
                            (*buf).items[ti][0] = rand()%80+1;
                            (*buf).items[ti][2] = getpid();
                            printf("[P%d] produced %2d\n",getpid(),(*buf).items[ti][0]);
                            (*buf).produced++;
                            break; 
                        }
                }
                sleep(1);
                exit(0); 
            } else  {
                if((*buf).consumed<(*buf).produced){
                    consumer_branch = fork();
                    if(consumer_branch < 0) {
                        printf("Error");
                        exit(1);
                    } else if (consumer_branch == 0) {
                        //Consume
                        //Check if produced
                        while((*buf).produced<=(*buf).consumed)
                            sleep(1);
                        //Find filled buffer
                        int ti,trand;
                        srand(time(0)); 
                        sleep(1);
                        for(ti = trand; ti < 25+trand; ti++)
                            if((*buf).items[ti%25][1]==1){                                                                
                                ti = ti%25;
                                (*buf).items[ti][1] = -1 ; //consumed
                                (*buf).TOTAL += (*buf).items[ti][0];
                                printf("[C%d] consumed %2d, produced by [P%d]\n",getpid(),(*buf).items[ti][0],(*buf).items[ti][2]);
                                (*buf).consumed++;
                                break;
                            }
                        exit(0); 
                    }
                    else{
                        wait(NULL);          
                    }
                }
                wait(NULL);          
            }
        }
    }
    else{
        wait(NULL);
        consumer_branch = fork();
        if(consumer_branch < 0) {
            printf("Error");
            exit(1);
        } else if (consumer_branch == 0) {
            //Consume
            //Check if produced
            while((*buf).produced<=(*buf).consumed)
                sleep(1);
            //Find filled buffer
            int ti,trand;
            srand(time(0)); 
            trand = 0;
            sleep(1);
            for(ti = trand; ti < 25+trand; ti++)
                if((*buf).items[ti%25][1]==1){                                                                
                    ti = ti%25;
                    (*buf).items[ti][1] = -1 ; //consumed
                    (*buf).TOTAL += (*buf).items[ti][0];
                    printf("[C%d] consumed %2d, produced by [P%d]\n",getpid(),(*buf).items[ti][0],(*buf).items[ti][2]);
                    (*buf).consumed++;
                    break;
                }
            exit(0); 
        }
        else{
            wait(NULL);          
        }
        printf("All producers and consumers are finished\nBuffer Status:\n");
        printf("TOTAL: %d\n",(*buf).TOTAL);
    }
    munmap(buf, sizeof *buf);
}
int main() 
{ 
    createProcess(); 
    return 0; 
}
