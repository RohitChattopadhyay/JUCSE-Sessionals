          /*program to calculate sum and average of four numbers and print the same */
#include<stdio.h> 
int main()                       /*beginning of main function  */
{
	int number,loop1;            /* integer type variable of number and loop1 are created */
	float average,sum=0.0;           /* average and sum are declared */
	printf("Enter the 4  numbers :\n");
	for(loop1=0;loop1<4;loop1++)     
	{
		scanf("%d",&number);                  
		sum+=number;
	}
	average=sum/4;                                    /* calculating average of four numbers*/
	printf("sum of the numbers:%f\n",sum);            /* printing sum of 4 number*/
	printf("average of the numbers:%f \n",average);          /* printing average of 4 number*/
	return 0;
}                                                           /* exit of function main */
