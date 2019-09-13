sp4.c

Type
C
Size
1 KB (1,126 bytes)
Storage used
0 bytesOwned by someone else
Location
clab rohit
Owner
Priti Shaw
Modified
9:39 PM by me
Opened
10:12 PM by me
Created
Apr 9, 2018
Add a description
Viewers can download
/*program to find the minimum and maximum numbers among 3 numbers */
#include<stdio.h>
#include<limits.h>
int main()                                     /*beginning of main function*/
{
	int max,min,number,loop;                          /*integer type variables are declared*/
        min=INT_MAX,max=INT_MIN;                       /*variable min and max are intialised by 1000 and 0 respectively*/
        printf("enter the numbers:");         /*taking numbers from user*/
        for(loop=0;loop<3 ;loop++)                     /* loop for taking 3 numbers*/
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
        printf("maximum among three numbers  are:%d\n",max);       /*printing maximum among three numbers*/
        printf("minimum among three numbers are:%d",min);          /*printing minimum among three numbers */
        return 0;
}                                            /* end of function main*/

