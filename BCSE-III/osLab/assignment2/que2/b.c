#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

static int * j;  
void createProcess() 
{   
j = mmap(NULL, sizeof *j, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *j = 0;
    int pi_d ;
    int pid ;
    pi_d = fork();
    if(pi_d == 0){
    // First process
        for(;*j<10;(*j)++){
            printf("Process B(%4d) is at iteration %2d\n",getpid(),*j);
            sleep(rand()%5);
        }
    }
    else{
        if(pi_d > 0){
            pid = fork();
            if(pid == 0){      
                // Second process
                wait(NULL);
                int i = 0;
                while(i<10){
                    if(*j>i-1) {
                        printf("Process A(%4d) is at iteration %2d Process B is at %d\n",getpid(),i++,*j);
                        sleep(rand()%5);
                    }
                }
                munmap(j, sizeof *j);
            }
        }
    }
}
int main() 
{ 
    createProcess(); 
    return 0; 
}