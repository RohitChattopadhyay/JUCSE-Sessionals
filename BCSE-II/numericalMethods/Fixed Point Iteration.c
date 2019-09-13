// Implementation of Fixed Point Method in c language

//Including libraries
#include<stdio.h>
#include<math.h>
//defining constants
#define EPSILON 1E-6 // floating point precision

//mathamatical functions
//first function

// function value at x
double f(double x) {
	return x * x  - x - 6; // f(x) = x^2 - x - 6
}

// value of g(x) according to fixed pt iteration method
double g(double x) {
	return sqrt(x + 6); // g(x) = sqrt( x + 6 )
}

// order of convergence based on current and previous errors
double ord_of_conv(double err, double prev_err) {
	err = fabs(err);
	prev_err = fabs(prev_err);
	return fabs(log(err) / log(prev_err));
}

//main function
int main() {
	int iter_number = 1; // number of iterations
	double x, prev, error, prev_error, ord_conv;
	// x - current approximation of root, prev - previous approximation
	// error - current error, prev - previous error
	// ord_conv - order of convergence
	
	// accept the value of initial approximation
	printf("Please enter the initial approximation = ");
	scanf("%lf", &x);
	
	prev = x; // set previous value of x
	
	// open a file in write mode for output
	FILE *fp = fopen("../outputs/4.txt", "w");
	
	// headings
	fprintf(fp, "Fixed Point iteration method implementation in C language\n");
	fprintf(fp, "\nIter #\tX\t\tPrev X\t\tError\t\tOrder of Convergence\n\n");
	
	do {
		x = g(prev); // new approximation
		
		error = x - prev; // error
		
		ord_conv = ord_of_conv(error, prev_error); // find order of convergence
		
		// print to file
		fprintf(fp, "%d\t%lf\t%lf\t%lf\t%lf\n", iter_number, x, prev, fabs(error), ord_conv);
		
		prev = x; // previous value of x
		prev_error = error; // set the previous value of error
		iter_number++; // increase no. of iterations
	} while (fabs(error) > EPSILON); // continue while error is greater than precision value
	
	// print value of root to file
	fprintf(fp, "\nResult\nRoot at x = %lf\nNumber of iterations = %d\n", x,iter_number-1);
	printf("\nResult\nRoot at x = %lf\nNumber of iterations = %d\n", x,iter_number-1);
	fclose(fp); // closing the file
	
	return 0;
}
