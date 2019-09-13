 /*program to print the prime factors of the given number*/ 
#include <stdio.h>
#include <math.h>
int main(void)  /*beginning of main function*/
{
	int input,loop1=3,sqroot,temp;
	printf("Enter Number\n");
	scanf("%d",&input);                    /*number is taken from the user*/
	printf("Prime factors of %d are 1",input);                   /*displaying prime factors of the given number*/
	temp=input;
	sqroot=sqrt(input);                  /*square root of the given number is calculated with the help of function sqrt()*/
	while(input%2==0)
	{
	 printf(" x 2"); 
	 input/=2;
	}
	for(loop1=3;loop1<=sqroot;loop1+=2)
	{
		while(input%loop1==0)
		{ printf(" x %d",loop1);
		 input/=loop1;
		}
	}
	if(input==temp)
	{
	printf(" x %d\n%d is a prime number",input,input);
	}
	else if(input>=sqroot)
	{
	printf(" x %d",input);
	}
	printf("\n");               /*printing new line*/
}                     /*end of main function*/


