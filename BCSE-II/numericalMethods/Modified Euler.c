//Implementation of Modified Euler in C language
//Including libraries
#include <stdio.h>
#include <math.h>
#define EPS 1E-6 // floating point precision value

// value of the funtion f(x, y) at given x and y values
// according to form of  dy/dx = f(x, y)
double f(double x, double y) {
	return y - x;
}

int main() {
	int iteration = 1; // the step number
	double y, y_prev, x0, y0, h, x_final, error;
	// open a file to write output to
	FILE *fp = fopen("../outputs/14.txt", "w");
        // take as input x0, y0, x(final) and h
	printf("Please Enter x0: "); 
	scanf("%lf",&x0);
	printf("Please Enter y0: "); 
	scanf("%lf",&y0);
	printf("Please Enter x final: "); 
	scanf("%lf",&x_final);
	printf("Please Enter h: "); 
	scanf("%lf",&h);
	// display the headings
	fprintf(fp, "Implementation of Modified Euler in C language\n\nx0 = %lf\ty0 = %lf\tx_final = %lf\th = %lf\n\n",x0,y0,x_final,h );
	fprintf(fp, "%15s%15s%15s%15s%15s\n", "Step", "x(i)", "y(i)", "y(i+1)", "Error");
        // continue the iteration while x is less than required final x
	while (x0 < x_final - EPS) {
                
                // display the initial values after before iteration
		fprintf(fp, "%15d%15lf%15lf%15s%15s\n", iteration++, x0, y0, "", "");
		// calc y(i) upto required precision
		// set initial y according to euler formula
		y = y + h * f(x0, y0);
		// display initial y
		fprintf(fp, "%15s%15s%15s%15lf%15s\n", "", "", "", y, "");
                // calculate a new approximation for y(i)
		do {
			y_prev = y; // set prev value
			// calculate new approximation for y(i)
			y = y0 + 0.5 * h * (f(x0, y0) + f(x0 + h, y_prev));
			error = fabs(y - y_prev);

                        // display the y and corresponding errors
			fprintf(fp, "%15s%15s%15s%15lf%15lf\n", "", "", "", y, error);
		} while ( error > EPS ); // continue until error is > than precision
		// update the initial x and y value
		x0 += h;
		y0 = y;
	}
    // display the final answer
	fprintf(fp, "\nResult\n\ty(%lf) = %lf\n", x_final, y);
	printf("\nResult\n\ty(%lf) = %lf\n", x_final, y);
	fclose(fp); // close the file
	return 0;
}
