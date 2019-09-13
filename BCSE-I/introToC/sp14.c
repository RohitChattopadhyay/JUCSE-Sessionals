 /*program to convert the decimal number to its binary equivalent and print the same */
#include<stdio.h>
int main()                                          /* beginning of the function main */
{
	int decimal,remainder,last_digit,inter;        /* variables of integer type are declared */
    int loop1=0,store=0;                        /* variable loop1 and store is intialised by 0 */
	scanf("%d",&decimal);                        /* taking decimal number from user   */
	while(decimal>0)                           
	 {
	  remainder=decimal%2;        
           if(remainder==0)
            {
               remainder=2;
            }
          decimal=decimal/2; 
          store=store*10+remainder;                   /*  storing the value of the variable store */ 
        }
         for( loop1;store>0;loop1++)                  
        {
                 last_digit= store%10;               /* logic for reversing a number */ 
                 inter=store/10;
                 store=inter;
                 if(last_digit==2)
                 {
                     last_digit=0;
                 }
                 printf("%d",last_digit);           /* printing the binary equivalent of the variable decimal  */
                
         }
  return 0;
}                                                  /* end of main function */

