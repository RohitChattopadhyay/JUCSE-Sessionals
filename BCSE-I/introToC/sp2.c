         /*program to  convert integer number to its equivalent roman*/
#include<stdio.h>
int main(void){            /*beginning of main function*/
	int iNum; 
	while (scanf("%d",&iNum)){                       /*taking number from user*/
		if(iNum>9999 || iNum<1) printf("Error");     
		else{
			printf("%4d in Roman is ",iNum);
			if(iNum>=5000){
				printf("N");iNum-=5000;          /*printing N if number>=5000*/
			}
			while(iNum>=1000){
				printf("M");iNum-=1000;         /*printing M if number>=1000*/
			}
			if(iNum>=500){
				printf("D");iNum-=500;          /*printing D if number>=500*/
			}
			while(iNum>=100){
				printf("C");iNum-=100;          /*printing C if number>=100*/      
			}
			if(iNum>=99){
				printf("XCIX");iNum-=99;        /*printing XCIX if number>=99*/
			}
			if(iNum>=50){
				printf("L");iNum-=50;           /*printing L if number>=50*/
			}
			if(iNum>=49){
				printf("XLIX");iNum-=49;       /*printing XLIX if number>=49*/
			}
									
			while(iNum>=10){
				printf("X");iNum-=10;          /*printing X if number>=10*/
			}
			if(iNum>=9){
				printf("IX");iNum-=9;          /*printing IX if number>=9*/
			}		
			if(iNum>=5){
				printf("V");iNum-=5;          /*printing V if number>=5*/
			}
			if(iNum>=4){
				printf("IV");iNum-=5;         /*printing IV if number>=4*/
			}
			while(iNum>=1){
				printf("I");iNum-=1;         /*printing I if number>=1*/
			}			
		}
		printf("\n");                      /*printing new line*/
	}
}                                            /*end of main function */
