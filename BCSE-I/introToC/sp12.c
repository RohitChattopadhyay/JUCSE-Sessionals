 /*program to print the prime factors of the given number*/ 
#include <stdio.h>
#include <math.h>
int main()  /*beginning of main function*/
{
	int input,loop1=3,sqroot;
	printf("Enter Number\n");             
	scanf("%d",&input);              /*number is taken from the user*/
	printf("Prime factors of %d are 1",input);       /*displaying prime factors of the given number*/
	sqroot=sqrt(input);              /*square root of the given number is calculated with the help of function sqrt()*/
	if(input%2==0)             
	{
	   while(input%2==0) 
	  {
	     input/=2;
	  }
	       printf(" , 2");        
	}
	for(loop1=3;loop1<=sqroot;loop1+=2)              
	{
		 if(input%loop1==0)
		   {
		 while(input%loop1==0)
		 {
		  input/=loop1;
		 }
		 printf(" , %d",loop1);
		   }
	}
    if(input>=sqroot)
	{
	 printf(" , %d",input);
	}
	printf("\n");                                                 /*printing new line*/
}                                    /*end of main function*/
