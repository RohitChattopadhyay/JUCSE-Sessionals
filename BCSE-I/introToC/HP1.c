/*Invert a given real number, reverse the number eg i/p : 123.4567; o/p : 7654.321 */ 
#include <stdio.h >
int main()                               /*beginning of main function*/
 {  
	int comparisionVariableorary,comparisionVariable,comparisionVariable2,leftOfDecimal; /*integer type variables are declared*/
	float input,tempRightOfDecimal,rightOfDecimal;   /*float type variables are declared*/
	while(scanf("%f",&input)){
		comparisionVariable2=1;  /*variable comparisionVariable2 is intialised with 1 and tempRightOfDecimal with input*/
		tempRightOfDecimal=input;
		while(comparisionVariable!=tempRightOfDecimal){   /*for printing right part of floating number*/
			tempRightOfDecimal*=10;
			comparisionVariable2*=10;
			comparisionVariable=tempRightOfDecimal;	
		}
		
		leftOfDecimal=comparisionVariable/comparisionVariable2;
		rightOfDecimal=comparisionVariable-(comparisionVariable/comparisionVariable2)*comparisionVariable2;
                                                    /*for printing left part of floating number*/
		comparisionVariableorary=rightOfDecimal;
		comparisionVariable2=rightOfDecimal;
		while(comparisionVariableorary>0){
			printf("%d",comparisionVariable2%10);
			comparisionVariable2=(comparisionVariable2-comparisionVariable2%10)/10;
			comparisionVariableorary/=10;		
		}
		printf(".");  
		comparisionVariableorary=leftOfDecimal;    /*merging two parts of floating number*/
		comparisionVariable2=leftOfDecimal;
		while(comparisionVariableorary>0){
			printf("%d",comparisionVariable2%10);
			comparisionVariable2=(comparisionVariable2-comparisionVariable2%10)/10;
			comparisionVariableorary/=10;		
		}
		printf("\n");         /*merging two parts of floating number*/ /*merging two parts of floating number*/
	}
 }                  /* end of main function*/
