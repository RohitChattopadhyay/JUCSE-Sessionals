#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void removeSubstr (char *string, char *sub) {
    char *match;
    int len = strlen(sub);
    while ((match = strstr(string, sub))) {
        *match = '\0';
        strcat(string, match+len+1);
    }
}

int main(){
        char command[75];
        char temp[75];
        char options[50];
        while(1){
                printf("BCSE!!> ");
                fgets(command, 75, stdin); 
                strncpy(temp, command, 75);
                strncpy(options, command, 75);
                char* prog = strtok(temp, " "); 
                removeSubstr(options,prog);
                strtok(prog, "\n");
                if(strcmp(prog,"dirnew")==0){
                        if(strlen(options)>1){
                                strcpy(command, "mkdir ");      
                                strcat(command, options);
                                system(command);
                        }
                        else
                                printf("dirnew: missing operand\n");
                        
                }
                else if(strcmp(prog,"editfile")==0){
                        strcpy(command, "vi ");
                        if(strlen(options)>1) strcat(command, options);
                        system(command);
                }
                else if(strcmp(prog,"info")==0){
                        strcpy(command, "ls -l ");
                        if(strlen(options)>1) strcat(command, options);
                        system(command);
                }
                else if(strcmp(prog,"exitnewshell")==0){
                        printf("Thank You! Have a nice day.\n");
                        exit(0);
                }
                else{
                       printf("%s: command not found\n",prog);
                }
        }
}
