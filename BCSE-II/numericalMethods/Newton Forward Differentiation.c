//Implementation of Newton Forward Differentiation in C language
//Including libraries
#include <stdio.h>
//Defining constants
#define MAX_N 30 // max no. of data value pairs of input

// function to write 1d array to file
void disp1D(FILE *fp, double arr[MAX_N], int n) {
	int i;
	for (i = 0; i < n; i++)
		fprintf(fp, "%12lf", arr[i]);
	fprintf(fp, "\n");
}

// function to write 2d array to file
void disp2D(FILE *fp, double arr[MAX_N][MAX_N], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			fprintf(fp, "%12lf", arr[i][j]);
		fprintf(fp, "\n");
	}
}

int main(void) {
	int i, j, n;
	double fac, res, den, a, h, x[MAX_N], diff_table[MAX_N][MAX_N];
	// open a file to write output to
	FILE *fp = fopen("../outputs/18.txt", "w");
	fprintf(fp, "Implementation of Newton Forward Differentiation in C language\n\n");
        // accept no. of values n, and corresponding a and h values
	printf("Enter the value of n: "); scanf("%d", &n);
	printf("Enter the value of a and h: "); scanf("%lf %lf", &a, &h);

        // accept the x-y value pairs
	printf("Enter x and corresponding y values:\n");
	for (i = 0; i < n; i++) {
		x[i] = (i != 0) ? x[i-1] + h : a;
		printf("x = %12lf, y = ", x[i]); scanf("%lf", &diff_table[i][0]);
	}

        // write the x values and the initial difference table to file
	fprintf(fp, "X Values:\n"); disp1D(fp, x, n);
	fprintf(fp, "\nDifference Table:\n"); disp2D(fp, diff_table, n);

        // populate the diff table
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			diff_table[j][i] = diff_table[j + 1][i - 1] - diff_table[j][i - 1];
		}
	}

        // write the populated diff table to file
	fprintf(fp, "\nDifference Table:\n"); 
        disp2D(fp, diff_table, n);

        // display differentiation point (a)
	fprintf(fp, "\nDifferentiate at x = %12lf\n", x[0]);

        // calculate the differentiated value
	den = 1; // denominator
	res = 0; // result
	fac = 1; // multiplying factor(1 or -1)
	for (i = 1; i < n; i++) {
		res += fac * diff_table[0][i] / den;
		fac = -fac;
		den++;
	}
	res/= h; // divide by h-value
        // write the result to the file
	fprintf(fp, "\nResult\nDifferentiated value is = %12lf\n", res);
	printf("Differentiated value is = %12lf\n", res);
	fclose(fp); // close the file
	return 0;
}
