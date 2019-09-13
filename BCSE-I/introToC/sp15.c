/*Program to copy a file to a new file, where all small letters are converted to capital letters and vice versa*/
#include <stdio.h>
#include <stdlib.h>
int main()
{                            /*beginning of main function*/      
    FILE *ftext,*fcopy;   /* two files are created*/
    char letter;         /* char type varible is declared*/
    ftext = fopen("text.txt", "r" );      /* text.txt file is opened in read mode*/
    fcopy = fopen("copytext.txt","w");    /* copytext.txt file is opened in write mode*/
    if (ftext == NULL || fcopy == NULL)   
    {
        printf("Cannot open file \n");
        exit(0);
    } 
    letter = fgetc(ftext);      /*reading the contents from file*/
    while (letter != EOF)       /*loop will terminate until EOF is read*/
    {
          if (letter >= 'A' && letter <= 'Z') letter += 32;      /*converting the content*/
	      else if (letter >= 'a' && letter <= 'z') letter -= 32;
        fputc(letter,fcopy);          /*copying the content*/
        letter = fgetc(ftext);
    }
    printf("Converted");
    fclose(ftext);                /*files are closed*/
    fclose(fcopy);
    return 0;
}                       /*end of main function*/
