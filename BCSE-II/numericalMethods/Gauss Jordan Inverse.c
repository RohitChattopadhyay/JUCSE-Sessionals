//Implementation of Gauss Jordan Inverse Method in C language
//including libraries
#include <stdio.h>

// upper limit on number of unknowns to maintain integrity
#define MAX_N 30

// function to print the n x (n + 1) augmented matrix
void disp2D(double arr[MAX_N][MAX_N*2], int n, FILE *fp) {
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n *2; j++) {
                        if (j == n) fprintf(fp, "|");
                        fprintf(fp, "%10lf ", arr[i][j]);
                }
                fprintf(fp, "\n");
        }
        fprintf(fp, "\n");
}

int main() {
        int i, j, k, n; // i, j, k - loop variables, n - number of unknowns
        double A[MAX_N][MAX_N * 2]; // augmented matrix
        //initialize the file pointer
        FILE *fp = fopen("../outputs/8.txt", "w"); // open output file for writing to
        fprintf(fp,"Gauss Jordan Inverse method implementation in C language\n\n");
        // accept the number of unknowns as input from user
        printf("Please enter the order of matrix: ");
        scanf("%d", &n);
        
        // accept the initial matrix A as input using nested loop
        printf("Please enter the matrix:\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        printf("A[%d, %d] = ", i+1, j+1); 
                        scanf("%lf", &A[i][j]);
                }
        }
        //generating the augmented matrix
        for (i = 0; i < n; i++) {
                A[i][i+n] = 1;
        }
        
        // display the initial matrix
        fprintf(fp, "Initial augmented matrix is\n");
        disp2D(A, n, fp);
        
        // perform gauss jordan elimination
        for (i = 0; i < n; i++) {
                // initial pivot index
                int p_i = i;
                
                // find the pivot based on largest A[index][i]
                for (j = i + 1; j < n*2; j++) {
                        if (A[p_i][i] < A[j][i])
                                p_i = j;
                }
                              
                // swap equation A[i] with A[pivot]
                for (j = i; j < n *2; j++) {
                        double temp = A[p_i][j];
                        A[p_i][j] = A[i][j];
                        A[i][j] = temp;
                }
                
                // elimination process
                for (j = 0; j < n; j++) {
                        if (i == j) continue; // current row / equation
                        
                        double fac = A[j][i] / A[i][i];
                        for (k = i; k < n*2; k++) {
                                A[j][k] = A[j][k] - fac * A[i][k];
                        }
                }
                
                // display the augmented matrix after each iteration
                fprintf(fp, "Iteration number %d, Augmented matrix now is\n", i + 1);
                disp2D(A, n, fp);
        }
        
        // left matrix is currently diagonal matrix
        // make the left matrix as an identity matrix
        for (i = 0; i < n; i++) {
                double fac = A[i][i];
                A[i][i] /= fac;
                for(j=n;j<n*2+1;j++)
                        A[i][j] /= fac;
        }
        
        // print the final augmented matrix
        fprintf(fp, "\nFinal augmented matrix is\n");
        disp2D(A, n, fp);
        printf("\nFinal augmented matrix is\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < n*2; j++) {
                        if (j == n) printf("|");
                        printf("%10lf ", A[i][j]);
                }
                printf("\n");
        }

        printf("\n\nResult\nInverse matrix is\n");
        fprintf(fp,"\n\nResult\nInverse matrix is\n");
        for (i = 0; i < n; i++) {
                for (j = n; j < n*2; j++) {
                        printf("%10lf ", A[i][j]);
                        fprintf(fp, "%10lf ", A[i][j]);
                }
                printf("\n");
                fprintf(fp,"\n");
        }
        fclose(fp); // close the file
        return 0;
}
