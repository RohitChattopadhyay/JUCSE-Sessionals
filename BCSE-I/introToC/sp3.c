/*Program to convert integer numbers to words */
#include<stdio.h>
int main()   /* beginning of main function*/
{
	int n,a,b,c;      /* integer type varibles are declared */                    
	scanf("%d",&n);   /* value of n is taken from user*/
    a=n/100;          
	b=(n-a*100)/10; 
    c=n%10;
	
	if(a!=0)                            /*if a is not equal to 0*/
	{                                             /*nested if else */
		if(a==1)
		printf("one hundred and");                    /*if a is equal to 1 then it will print one hundred and*/
		else if(a==2)
		printf("two hundred and");                  /*if a is equal to 2 then it will print two hundred and*/
		else if(a==3) 
		printf("three hundred and");                /*if a is equal to 3 then it will print three hundred and*/
		else if(a==4)
		printf("four hundred and");                /*if a is equal to 4 then it will print four hundred and*/
		else if(a==5)
		printf("five hundred and");                /*if a is equal to 5 then it will print five hundred and*/
		else if(a==6)
		printf("six hundred and");                 /*if a is equal to 6 then it will print six hundred and*/
		else if(a==7)
		printf("seven hundred and");              /*if a is equal to 7 then it will print seven hundred and*/
		else if(a==8)
		printf("eight hundred and");              /*if a is equal to 8 then it will print eight hundred and*/
		else if(a==9)
		printf("nine hundred and");               /*if a is equal to 9 then it will print nine hundred and*/
	}
	if(b!=0)                        /*if b is not equal to 0*/
		{
		if(b==1)
		printf(" onety");                  /*if b is equal to 1 then it will print onety */
		else if(b==2)
		printf(" twenty");                 /*if b is equal to 2 then it will print twenty */
		else if(b==4)
		printf(" fourty");                 /*if b is equal to 3 then it will print fourty */
		else if(b==3)
		printf(" thirty");                 /*if b is equal to 4 then it will print thirty */
		else if(b==5)
		printf(" fifty");                  /*if b is equal to 5 then it will print fifty */
		else if(b==6)
		printf(" sixty");                  /*if b is equal to 6 then it will print sixty */
		else if(b==7)
		printf(" seventy");                /*if b is equal to 7 then it will print seventy */
		else if(b==8)
		printf(" eighty");                 /*if b is equal to 8 then it will print eighty */
		else if(b==9)
		printf(" ninety");                 /*if b is equal to 9 then it will print ninety */
	}
	if(c!=0)                      /*if c is not equal to 0*/
	{
		if(c==1)                             /*if c is equal to 1 then it will print one */
		printf(" one");
		else if(c==2)                        /*if c is equal to 2 then it will print two */
		printf(" two");
		else if(c==3)                        /*if c is equal to 3 then it will print three */
		printf(" three");                            
		else if(c==4)                       /*if c is equal to 4 then it will print four */
		printf(" four");
		else if(c==5)                       /*if c is equal to 5 then it will print five */
		printf(" five");
		else if(c==6)                       /*if c is equal to 6 then it will print six */
		printf(" six");
		else if(c==7)                       /*if c is equal to 7 then it will print seven */
		printf(" seven");
		else if(c==8)                        /*if c is equal to 8 then it will print eight*/
		printf(" eight");
		else if(c==9)                       /*if c is equal to 9 then it will print nine */
		printf(" nine");
		
	}
}                                         /*end of main function */
