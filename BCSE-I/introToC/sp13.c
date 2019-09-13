/* program to find the accuracy between the sum (1/n + 1/n + … n times) and 1. Also, display the result */
#include<stdio.h>
#include<math.h>     /*declared for using fabs function */
int main()             /* beginning of function main*/
{
	int number,loop;            /*integer type variables are declared */
	float sum=0;        /* variable sum is intialised with 0 */
	scanf("%d",&number);        /*value of n is taken from the user */
	for ( loop=0;loop<number+1;loop++) 
		{ 
	  sum+=1/(float)number;    /* sum is calculated */
	} 
	printf("%f %f",sum,fabs(sum-1)*100);      /* displaying the accuracy */
}                                             /* end of main function*/ 
