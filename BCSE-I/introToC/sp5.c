/*program to find the minimum and maximum numbers among 4 numbers */
#include<stdio.h>
#include<limits.h>
int main()                                     /*beginning of main function*/
{
	int max,min,number,loop;                          /*integer type variables are declared*/
        min=INT_MAX,max=INT_MIN;                       /*variable min and max are intialised by 1000 and 0 respectively*/
        printf("enter the numbers:");         /*taking numbers from user*/
        for(loop=0;loop<4 ;loop++)                     /* loop for taking 4 numbers*/
        {
            scanf("%d",&number); 
            if(number>max)                          
            {
        	max=number;
            }
            if(number<min)
            {
            	min=number;
             }
         }
        printf("maximum among four numbers  are:%d\n",max);       /*printing maximum among four numbers*/
        printf("minimum among four numbers are:%d",min);          /*printing minimum among four numbers */
        return 0;
}                                            /* end of function main*/
