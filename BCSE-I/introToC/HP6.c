/*In the file, search for a two digit number. If the number exists, then count the frequency of the two digit number.*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main () {          /*beggining of main function*/
   int year,inp,search,count=0;  /*integer type variables are declared and count is intialised with 0*/
   FILE * fp;             /*file pointer is created*/
   fp = fopen ("file.txt", "r");      /*file is opened in read mode*/
   scanf("%d",&search); // number to search
   while(fscanf(fp, "%d",&inp))       /*reading contents in the file*/
   {    if (inp==search) 
        count++;	
   }
   printf("Found %d times \n", count );  /*printing count*/
   fclose(fp);               /*file is closed*/
   return(0);                /*end of main function*/
}
