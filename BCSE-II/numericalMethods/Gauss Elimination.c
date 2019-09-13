//implementation of Gaussian Elimination in C
//including libraries
#include <stdio.h>

// upper limit on no. of unknowns
//defining constants
#define MAX_N 30

// display the 2D augmented matrix A
void print2D(double arr[MAX_N][MAX_N], int n, FILE *fp) {
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n + 1; j++) {
                        if (j == n) fprintf(fp, "|"); // separate constants
                        fprintf(fp, "%10lf ", arr[i][j]);
                }
                fprintf(fp, "\n");
        }
        fprintf(fp, "\n");
}

int main() {
        int i, j, k, n;
        double A[MAX_N][MAX_N], X[MAX_N];
        // A - augmented matrix, X - solution matrix
        
        // file for writing output
        FILE *fp = fopen("../outputs/5.txt", "w");
        
        // accept the number of unknowns n
        printf("Enter Number of unknowns: ");
        scanf("%d", &n);
        
        // accept the initial matrix A as in gauss elimination
        printf("Enter the augmented matrix A:\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < n + 1; j++) {
                        //taking matrix from user
                        printf("A[%d, %d] = ", i+1, j+1); 
                        scanf("%lf", &A[i][j]);
                }
        }
        
        // write the initial matrix to the output file
        fprintf(fp, "Gaussian Elimination method implementation in C language\n\nInitial augmented matrix is\n");
        print2D(A, n, fp);
        
        // perform gauss elimination
        for (i = 0; i < n-1; i++) {
                // implement partial pivoting
                
                int p_i = i; // initial pivot
                
                // find the pivot based on largest A[index][i]
                for (j = i + 1; j < n; j++) 
                        if (A[p_i][i] < A[j][i])
                                p_i = j;
                              
                // swap equation A[i] with A[pivot]
                for (j = i; j < n + 1; j++) {
                        double temp = A[p_i][j];
                        A[p_i][j] = A[i][j];
                        A[i][j] = temp;
                }
                
                // perform the elimination process
                // eliminate A[i+1 .. n][i]
                for (j = i + 1; j < n; j++) {
                        double fac = A[j][i] / A[i][i];
                        for (k = i; k < n + 1; k++)
                                A[j][k] -= fac * A[i][k];
                }
                
                // print current A to the file
                fprintf(fp, "Iteration Number %d, Augmented matrix now is\n", i + 1);
                print2D(A, n, fp);
        }
        
        // write the final matrix 
        fprintf(fp, "Final Augmented Matrix is\n");
        print2D(A, n, fp);
        
        // perform the back substitution process
        for (i = n - 1; i >= 0; i--) {
                X[i] = A[i][n]; // initial value coeff A[index][n+1]
                // subtract the rest of the terms
                for (j = i + 1; j < n; j++)
                        X[i] -= A[i][j] * X[j];
                X[i] /= A[i][i]; // divide by coeff of current term
        }
        // write the solution matrix to the file
        fprintf(fp, "Solution X is\n");
        printf("\nSolution:\n\n");
        for (i = 0; i < n; i++) {
                fprintf(fp, "X%d = %10lf\n",i+1, X[i]);
                printf("X%d = %10lf\n",i+1, X[i]);
        }
        
        fclose(fp); // close the file
        
        return 0;
}