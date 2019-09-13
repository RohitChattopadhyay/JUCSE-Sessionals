//implementation of Chebyshev method in C language

//incluing header libraries
#include<stdio.h>
#include<math.h>
//declaring constants
#define e 2.718281828
#define Pi 3.14159265

double func(double x){
	return pow(e,-x)-x; // function is y=e^(-x)-x
}

double derFunc(double x){
	return -1*pow(e,-x)-1; // derivative function is y'=-e^(-x)-1
}

double der2Func(double x){
	return pow(e,-x); // derivative function is y"=e^(-x)
}

int main(){
	double positionX=0;
	double decrement=1;
	double precision,prevDecrement;
	int iteration=1;
	
	//File Handling
	FILE *outputFile;			//intiating File Pointer
	outputFile=fopen("../outputs/3.txt","w");
	//creating table header
	fprintf(outputFile, "Chebyshev's method implementation in C language\n\n");
	fprintf(outputFile,"Iteration\tx\t\tf(x)\t\tf'(x)\t\tf\"(x)\t\tDecrement\tRelative Error\tOrder of Convergence(n)\n\n");
	
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
		prevDecrement=decrement;
		decrement =func(positionX)/derFunc(positionX) + (func(positionX)*func(positionX)*der2Func(positionX))/(2*derFunc(positionX)*derFunc(positionX)*derFunc(positionX));
		//creating table rows
		if(iteration == 1) 
		fprintf(outputFile,"%d\t\t%lf\t%lf\t%lf\t%lf\t%lf\n",iteration,positionX,func(positionX),derFunc(positionX),der2Func(positionX),decrement);
else		fprintf(outputFile,"%d\t\t%lf\t%lf\t%lf\t%lf\t%+lf\t%lf\t%lf\n",iteration,positionX,func(positionX),derFunc(positionX),der2Func(positionX),decrement,decrement/positionX,fabs(log(fabs(decrement))/log(fabs(prevDecrement))));
		//Changing the position of x
		positionX-=decrement;
		iteration++;
	}
	
	fprintf(outputFile,"\nThe value of root : %lf\n",positionX); //printing the root in output file
	fclose(outputFile); //closing file pointer
	//printinf result on terminal
	printf("The value of root : %lf\nTotal Iterations: %d\nSaved in output file.\n",positionX,iteration);
	return 0;
}
