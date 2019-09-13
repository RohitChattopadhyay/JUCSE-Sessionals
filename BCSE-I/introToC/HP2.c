/*Invert a given real number, reverse the number eg i/p : 123.4567; o/p : 321.7654 */
#include <stdio.h>
int main()                       /*beginning of main function*/
 {
        int comparisionVariableorary,comparisionVariable,comparisionVariable2,leftOfDecimal;/*integer type variables are declared*/
        float input,tempRightOfDecimal,rightOfDecimal;              /*float type variables are declared*/
        while(scanf("%f",&input)){
                comparisionVariable2=1;
                tempRightOfDecimal=input;    /*variable comparisionVariable2 is intialised with 1 and tempRightOfDecimal with input*/
                while(comparisionVariable!=tempRightOfDecimal){
                        tempRightOfDecimal*=10;    /*for printing right part of floating number*/
                        comparisionVariable2*=10;
                        comparisionVariable=tempRightOfDecimal;
                }
                leftOfDecimal=comparisionVariable/comparisionVariable2;
                rightOfDecimal=comparisionVariable-(comparisionVariable/comparisionVariable2)*comparisionVariable2;
                comparisionVariableorary=leftOfDecimal;
                comparisionVariable2=leftOfDecimal;
                while(comparisionVariableorary>0){
                        printf("%d",comparisionVariable2%10);      /*for printing left part of floating number*/
                        comparisionVariable2=(comparisionVariable2-comparisionVariable2%10)/10;
                        comparisionVariableorary/=10;
                }
                printf(".");
                comparisionVariableorary=rightOfDecimal;      /*merging two parts of floating number*/
                comparisionVariable2=rightOfDecimal; 
                while(comparisionVariableorary>0){
                        printf("%d",comparisionVariable2%10);
                        comparisionVariable2=(comparisionVariable2-comparisionVariable2%10)/10;
                        comparisionVariableorary/=10;
                }
                printf("\n");             /*merging two parts of floating number*/
        }                              /* end of main function*/
 }
