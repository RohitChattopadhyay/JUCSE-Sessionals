//Implementation of Multipoint Iteration in C language
//Including libraries
#include <stdio.h>
#include <math.h>
//defining constants
#define e 2.718281828 // value of e
#define EPS 1E-6 // floating point precision

// function value at x
double f(double x) {
	return pow(e, -x) - x;
}

// value of derivative of function at x
double der_f(double x) {
	return -pow(e, -x) - 1;
}

int main() {
	int iteration = 1; // number of iterations
	double x, prev, x_star, error, prev_error, ord_conv;
	// accept the value of initial approximation
	printf("Initial Approx of x:\t"); scanf("%lf", &x);
	
	prev = x; // set previous value of x
	
	// open a file in write mode for output
	FILE *fp = fopen("../outputs/15.txt", "w");
	
	fprintf(fp, "Implementation of Multipoint Iteration in C language\n\nInitial Approx of x: %lf\n\n%15s%15s%15s%15s%15s\tOrder of convergence\n", x,"Iter. no.", "x", "x*", "Prev x", "Error");
	
	do {
		x_star = prev - 0.5 * f(prev) / der_f(prev); // value of x* in multi-pt iteration
		x = prev - f(prev) / der_f(x_star); // value of next approximation
		
		error = x - prev; // error
		
		ord_conv = fabs(log(error) / log(prev_error)); // find order of convergence
		
		// print to file
		fprintf(fp, "%15d%15lf%15lf%15lf%15lf%15lf\n", iteration, x, x_star, prev, fabs(error), ord_conv);
		
		prev = x; // previous value of x
		prev_error = error; // set the previous value of error
		iteration++; // increase no. of iterations
	} while (fabs(error) > EPS); // continue while error is greater than precision value
	// print value of root to file
	fprintf(fp, "Result\n\tRoot at x = %lf\n", x);
	printf("Result\n\tRoot at x = %lf\n", x);
	fclose(fp); // closing the file
	return 0;
}

