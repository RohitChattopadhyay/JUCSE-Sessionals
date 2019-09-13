#include <stdio.h>
int main() //Declaring main function
 {
	int input,temporary;

	while(scanf("%d",&input)){
		temporary=input; // storing number
		while(temporary>0){
		//Splitting integers
			printf("%d\n",input%10);
			input=(input-input%10)/10;
			temporary/=10;		
		}
	}
 }
 //Ending main function
