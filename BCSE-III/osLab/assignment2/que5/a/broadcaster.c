#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd; 
  
    // FIFO file path 
    char * myfifo = "/tmp/os5a"; 
    mkfifo(myfifo, 0666); 
    char msg[80],msg1[80]; 
    printf("Broadcasting Center\n");
    while (1) 
    { 
        fd = open(myfifo, O_WRONLY); 
        printf("Enter message to broadcast:\t");
        fgets(msg, 80, stdin); 
        write(fd, msg, strlen(msg)+1); 
        write(fd, msg, strlen(msg)+1); 
        write(fd, msg, strlen(msg)+1); 
        write(fd, msg, strlen(msg)+1); 
        close(fd); 
    } 
    return 0; 
} 