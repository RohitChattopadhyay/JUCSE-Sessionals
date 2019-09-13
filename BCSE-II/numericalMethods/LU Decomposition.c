//Implementation of LU Decomposition Method in C language
//Including libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100  //defining max to 100 

//function to decompose matrix
void luDecomposition(int mat[][MAX], int n)
{
    FILE *fp;
    fp=fopen("../outputs/13.txt","w");
    fprintf(fp, "LU Decomposition method implementation in C languages\n\n");
    int lower[n][n], upper[n][n]; //initialize arrays
    memset(lower, 0, sizeof(lower)); //setting arrays to 0
    memset(upper, 0, sizeof(upper));
    int i,j,k;
    // Decomposing matrix into Upper and Lower
    // triangular matrix
    for (i = 0; i < n; i++) {
                                                 // Upper Triangular
        for (k = i; k < n; k++) {
            // Summation of L(i, j) * U(j, k)
            int sum = 0;
            for (j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);
            // Evaluating U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }
        // Lower Triangular
        for (k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1; //setting Diagonal as 1
            else {
                // Summation of L(k, j) * U(j, i)
                int sum = 0;
                for (j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);
                // Evaluating L(k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }
    // setw is for displaying nicely
    // Displaying the result :
    fprintf(fp,"LOWER TRIANGLE :\n\n");
    printf("LOWER TRIANGLE :\n\n");
    for (i = 0; i < n; i++) {
        // printing the lower triangle 
        for (j = 0; j < n; j++){
            fprintf(fp,"%d\t",lower[i][j]);
            printf("%d\t",lower[i][j]);
        }
        fprintf(fp,"\t\t\n");
        printf("\t\t\n");
}
   fprintf(fp,"\nUPPER TRIANGLE:\n\n");
   printf("\nUPPER TRIANGLE:\n\n");
   for (i = 0; i < n; i++) {
        // Upper Triangle
        for (j = 0; j < n; j++){
            fprintf(fp,"%d\t",upper[i][j]);   //printing the upper triangle 
            printf("%d\t",upper[i][j]);       //printing the upper triangle 
        }
        fprintf(fp,"\t\n");
        printf("\t\n");
    }
fprintf(fp,"\n");
printf("\n");
}

int main()
{   //beginning of main function
    int mat[MAX][MAX] = {
                    { 2, -1, -2 },         //input matrix
                    { -4, 6, 3 },
                    { -4, -2, 8 }
                };
    luDecomposition(mat, 3); //calling luDecomposition() function to decompose
    return 0;
}