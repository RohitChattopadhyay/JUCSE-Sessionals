           /*program to print the Pascal’s Triangle for n rows*/
#include <stdio.h>
int main()                     /* beginning of main function*/
{
    int numRows, coef = 1, printSpace, loop1, loop2;   /* integer type of variables are declared */
    scanf("%d",&numRows);     /*scanning the number of rows for printing pascal triangle*/

    for(loop1=0; loop1<numRows; loop1++)              
    {
        for(printSpace=1; printSpace <= numRows-loop1; printSpace++)         /*loop for printing blankspace*/
            printf("  ");

        for(loop2=0; loop2 <= loop1; loop2++)
        {
            if (loop2==0 || loop1==0) coef = 1;
            else coef = coef*(loop1-loop2+1)/loop2;
            printf("%4d", coef);                          
        }
        printf("\n");           /*printing the new line*/
    }
    return 0;
}                                                /* end of function main*/


