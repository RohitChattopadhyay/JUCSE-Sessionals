//implementation of Bisection method in C language

//incluing header libraries
#include<stdio.h>
#include<math.h>
//declaring constants
#define e 2.718281828
#define Pi 3.14159265

//Function for returning value f(x); returns double
double equationFunc(double X){
	return X*X-3; // function is x^2-3
}

int main(){
	double lower,higher,middle,precision,prevRoot;	//intiating double variables
	int iteration=1; 				//intiating iteration counter

	//taking user inputs
	printf("Enter the lower value of interval(a)\n");
	scanf("%lf",&lower);				//scanning Lower of interval
	printf("Enter the higher value of interval(b)\n");
	scanf("%lf",&higher);				//scanning Upper of interval
	
	//Checking bad inputs from user
	while(higher<=lower) {
		printf("ERROR : b should be higher than a\n");
		printf("Enter the lower value of interval(a)\n");
		scanf("%lf",&lower);				//scanning Lower of interval again
		printf("Enter the higher value of interval(b)\n");
		scanf("%lf",&higher);				//scanning Upper of interval again
	}
	printf("Enter the precision\n");
	scanf("%lf",&precision);			//scanning Precision
	while(precision<=0){
		printf("ERROR : Precision should be greater than 0\n");
		printf("Enter the precision\n");
		scanf("%lf",&precision); //scanning precision again
	}
	while((equationFunc(higher)*equationFunc(lower))>=0) {
		printf("ERROR : a and b are on same side\n");
		printf("Enter the lower value of interval(a)\n");
		scanf("%lf",&lower);				//scanning Lower of interval again
		printf("Enter the higher value of interval(b)\n");
		scanf("%lf",&higher);				//scanning Upper of interval again
	}
	
	//File Handling
	FILE *outputFile; 				//intiating File Pointer
	outputFile=fopen("../outputs/2.txt","w");
	//creating table header
	fprintf(outputFile, "Bisection method implementation in C language\n\na : %lf\nb : %lf\n\n",lower,higher );
	fprintf(outputFile,"Iteration\ta\t\tb\t\t(a+b)/2\t\tf((a+b)/2)\tf(a)*f(a+b)/2)\tRelative Error\n\n");
	
	while(fabs(higher-lower)>precision){
		prevRoot = middle; //saving previous root for calculation of relative error
		middle=(lower+higher)/2;
		//creating table rows
		fprintf(outputFile,"%d\t\t%lf\t%lf\t%lf\t%lf\t%lf\t%+lf\n",iteration,lower,higher,middle,equationFunc(middle),equationFunc(lower)*equationFunc(middle),fabs(prevRoot-middle)/middle);
		if(fabs(equationFunc(middle))<precision) break; //Root found
		else if ((equationFunc(middle)*equationFunc(lower))<0){ //checking on which half middle term lies
			higher=middle;
		}
		else {
			lower=middle;
		}
		//middle pointer shifted
		iteration++;
	}
	fprintf(outputFile,"\nThe value of root : %lf\n",middle); //printing the root in output file
	fclose(outputFile); //closing file pointer
	//output messages on terminal
	printf("The value of root : %lf\nTotal Iterations: %d\n",middle,iteration);
	return 0;
}