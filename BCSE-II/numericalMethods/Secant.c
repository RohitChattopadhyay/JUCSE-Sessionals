//Implementation of Secant Method in C language
//Including libraries
#include<stdio.h>
#include<math.h>
//Declaring universal constants
#define e 2.718281828
#define Pi 3.14159265

//function to be analysed
double func(double x){
	return pow(e,-x)-x; // function is y=e^(-x)-x
}

//main function
int main(){
	double positionX=0;
	double decrement=1;
	double minusOneX=1;
	double minusTwoX=0;
	double precision,prevDecrement;
	int iteration=1;
	
	//File Handling
	FILE *outputFile;				//intiating File Pointer
	outputFile=fopen("../outputs/24.txt","w");
	//creating table header
	fprintf(outputFile,"Implementation of Secant Method in C language\n\nIteration\tXn\t\tXn-1\t\tXn-2\t\tf(x)\t\tDifference\tRelative Error\tOrder of Convergence\n\n");
	
	//taking user input for precision
	printf("Enter the precision\n");
	scanf("%lf",&precision);			//scanning Precision
	while(precision<=0){
		//precision input validation
		printf("ERROR : Precision should be greater than 0\n");
		printf("Enter the precision\n");
		scanf("%lf",&precision); //scanning precision again
	}	
	
	while (fabs(decrement)>precision){
		minusTwoX=minusOneX;
		minusOneX=positionX;
		prevDecrement=decrement;
		decrement = (func(minusOneX)*(minusOneX-minusTwoX))/(func(minusOneX)-func(minusTwoX));
		//creating table rows
		positionX-=decrement;
		if(iteration == 1) 
		fprintf(outputFile,"%d\t\t%lf\t%lf\t%lf\t%lf\t\n",iteration,positionX,minusOneX,minusTwoX,func(positionX));
		else
		fprintf(outputFile,"%d\t\t%lf\t%lf\t%lf\t%lf\t%+lf\t%lf\t%lf\n",iteration,positionX,minusOneX,minusTwoX,func(positionX),decrement,decrement/positionX,(double)fabs(log(fabs(decrement))/log(fabs(prevDecrement))));
		//Changing the position of x
		iteration++;
	}
	
	fprintf(outputFile,"\nThe value of root is %lf\n",positionX); //printing the root in output file
	fclose(outputFile); //closing file pointer
	//printinf result on terminal
	printf("The value of root is %lf\nTotal Iterations: %d\n",positionX,iteration);
	return 0;
}
