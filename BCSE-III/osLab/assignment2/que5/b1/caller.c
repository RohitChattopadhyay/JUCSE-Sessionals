#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[50]; 
    int sender;
} message; 
  
int main() 
{ 
  key_t key; 
  int msgid; 
  int callerid=951;
  printf("Calling...\n");
  // ftok to generate unique key 
  key = ftok("telephone", 65); 
  // msgget creates a message queue 
  // and returns identifier 
  msgid = msgget(key, 0666 | IPC_CREAT); 
  message.mesg_type = 1; 
  printf("Call connected\n");
  if(fork()==0){
    while(1){
      msgrcv(msgid, &message, sizeof(message), 1, 0); 
      if(message.sender==callerid){
        msgsnd(msgid, &message, sizeof(message), 0); 
        continue;  
      }
      printf("%*s\n",50,message.mesg_text); 
      if(strcmp(message.mesg_text,"bye")==0){
        printf("Call disconnected\n");
        msgctl(msgid, IPC_RMID, NULL); 
        exit(0);
      }
    }
  }
  else{
    while(1){
      message.mesg_type = 1; 
      gets(message.mesg_text);  
      message.sender = callerid;   
      msgsnd(msgid, &message, sizeof(message), 0); 
      if(strcmp(message.mesg_text,"bye")==0){
        printf("Call disconnected\n");
        msgctl(msgid, IPC_RMID, NULL); 
        exit(0);
      }
    }
  }
  return 0; 
} 