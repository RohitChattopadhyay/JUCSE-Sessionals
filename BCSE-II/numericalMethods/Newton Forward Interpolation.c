//Implementation of Newton Forward Interpolation in C language
//Including libraries
#include <stdio.h>
//Defining constants
#define MAXN 30 // number of interpolation points

// display a given 1d matrix
void disp1D(double arr[MAXN], int n, FILE *fp) {
        int i;
        for (i = 0; i < n; i++)
                fprintf(fp, "%12lf", arr[i]);
        fprintf(fp, "\n");
}

// display a given 2d matrix
void disp2D(double arr[MAXN][MAXN], int n, FILE *fp) {
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++)
                        fprintf(fp, "%12lf", arr[i][j]);
                fprintf(fp, "\n");
        }
}
//main function
int main() {
        int i, j, n; // n - no. of x values
        double fac,temp, res, val, a, h, x[MAXN], diff_table[MAXN][MAXN];
        // open a file to write output to
        FILE *fp = fopen("../outputs/17.txt", "w");
        
        // accept n, a and h as input
        printf("Please enter n: "); scanf("%d", &n);
        printf("Please enter a, h: "); scanf("%lf %lf", &a, &h);
        
        // take the y values as input to corres x = a + i*h
        for (i = 0; i < n; i++) {
                x[i] = (i != 0) ? x[i-1] + h : a;
                printf("x = %12lf, y = ", x[i]); 
	 	scanf("%lf", &diff_table[i][0]);
        }
        
        // write initial x values and diff table
        fprintf(fp, "Implementation of Newton Forward Interpolation in C language\n\nX values are:\n"); disp1D(x, n, fp);
        fprintf(fp, "\nInitial diff table:\n"); disp2D(diff_table, n, fp);
        
        // calculating the difference table
        for (i = 1; i < n; i++)
                for (j = 0; j < n - i; j++)
                        diff_table[j][i] = diff_table[j + 1][i - 1]- diff_table[j][i - 1];
        
        // write the final difference table to the file
        fprintf(fp, "\nFinal difference table:\n");
        //printf table
        disp2D(diff_table, n, fp);
        
        // accept value at which interpolation is to be performed
        printf("Enter value to interpol at: ");
        scanf("%lf", &val);
        temp = val;
        // interpolate the value
        val = (val - a) / h; 
        res = 0; fac = 1;
        for (i = 0; i < n; i++) {
                res += fac*diff_table[0][i];
                fac *= (val - i) / (i + 1);
        }                           
 
        // write the result to the file       
        fprintf(fp, "\nResults\nInterpolated value at %lf= %lf\n",temp, res);
        printf("\nInterpolated value at %lf= %lf\n",temp, res);
        fclose(fp); // close the file
        
        return 0;
}
