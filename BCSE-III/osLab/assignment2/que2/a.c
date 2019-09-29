#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>

int j = 0;  
void createProcess() 
{   
  int pi_d ;
  int pid ;
  pi_d = fork();
  if(pi_d == 0){
    // First process
    for(int i = 0;i<10;i++){
        printf("Process A(%4d) is at iteration %d\n",getpid(),i+1);
        sleep(rand()%5);
    }
  }
  if(pi_d > 0){
    pid = fork();
    if(pid == 0){      
        // Second process
        for(int i = 0;i<10;i++){
            printf("Process B(%4d) is at iteration %d\n",getpid(),i+1);
            sleep(rand()%5);
        }
    }
  }
} 
int main() 
{ 
    createProcess(); 
    return 0; 
}