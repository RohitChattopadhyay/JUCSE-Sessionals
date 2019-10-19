#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h>

void timestamp()
{
    time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    char *stamp = asctime( localtime(&ltime) ) ;
    stamp[strlen(stamp) - 1] = 0;
    printf("%s ",stamp);
}

int main() 
{ 
    int fd1; 
  
    // FIFO file path 
    char * myfifo = "/tmp/os5a"; 
  
    mkfifo(myfifo, 0666); 
  
    char str[80],str2[80]; 
    while (1) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str, 80); 
        // Print the read string and close 
        if(strcmp(str,str2)!=0){
            timestamp();
            printf("[R%d] Received Broadcast:\t%s",getpid(), str); 
            strcpy(str2,str);
        }
        close(fd1); 
        fd1 = open(myfifo,O_WRONLY);
        write(fd1, str, strlen(str)+1); 
        close(fd1); 
    } 
    return 0; 
} 