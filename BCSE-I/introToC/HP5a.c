/* program to make a file, data.txt with 6 columns, where each column will have 6 integer numbers.
 The file will have 50 rows of the types of described columns. */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()                        /*beginning of main function*/
{
    FILE *fcopy;          /*file fcopy is created*/
    char letter;          /*char type variable is declared*/
    int row=1;            /*row is intaialised with 1*/
    fcopy = fopen("data.txt","w");  /*file is opened in write mode*/
    if (fcopy == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    // Reading contents from file
    while (row != 51)    /*reading contents from the file*/
    
    {
        srand ( row );                 /*contents are copied from the file */
        fprintf(fcopy, "%d\t %d\t %d\t %d\t %d\t %d\n", row, rand(), rand(), rand(),rand(),rand()); /* 6 columns are generated*/
        row++;                      /*row is incremented by 1*/
    }
    printf("Done");
    fclose(fcopy);      /*file is closed*/
    return 0;
}                           /*end of main function*/
