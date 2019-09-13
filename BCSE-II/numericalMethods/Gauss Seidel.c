//Implementation of Gauss Seidel Method in C language
//including libraries
#include<stdio.h>
#include<math.h>

//main function
int main() {
    FILE * fp = fopen("../outputs/9.txt", "w"); //Opening a output file in write mode

    int n, loop1, loop2, loop3, big, pstn, count,flag;
    //Accepting the no. of unknown variables
    printf("Please enter the number of variables: ");
    scanf("%d", & n);

    float coeff[n][n + 1], diff, sum, m, x[n], x_new[n], max, temp;
    //Accepting the augmented matrix
    printf("\n\nPlease Enter the augmented matrix: \n");
    for (loop1 = 0; loop1 < n; loop1++) {
        for (loop2 = 0; loop2 <= n; loop2++) {
            printf("\nA[%d][%d] = ", loop1 + 1, loop2 + 1);
            scanf("%f", & coeff[loop1][loop2]);
        }
    }
    //output file
    fprintf(fp,"Gauss Seidel method implementation in C language\n\n");
    //To set the first approximation
    fprintf(fp, "Iter.\t");
    for (loop2 = 0; loop2 < n; loop2++) {
        x[loop2] = 0; //initial approximation of every unknown is set TO 0
        fprintf(fp, "x[%d]\t\t", (loop2 + 1)); //Creating the table headings in the output file
    }
    fprintf(fp, "Maximum Error\n"); //Creating the table headings in the output file

    count = 0;
    do {
        for (loop1 = 0; loop1 < n; loop1++) {
            x_new[loop1] = coeff[loop1][n];
            //Xi(k+1)=Xi(k+1)-(aiq*Xq(k+1))
            for (loop2 = 0; loop2 < loop1; loop2++){
                x_new[loop1] -= (coeff[loop1][loop2] * x_new[loop2]);
            }
            //Xi(k+1)=Xi(k+1)-(aiq*Xq(k))
            for (loop2 = loop1 + 1; loop2 < n; loop2++){
                x_new[loop1] -= (coeff[loop1][loop2] * x[loop2]);
            }
            //Xi(k+1)=Xi(k+1)/a[i][i]
            x_new[loop1] = x_new[loop1] / coeff[loop1][loop1];
        }

        max = fabs(x_new[0] - x[0]); //the first approximate for max= absolute(X0(k+1)-X0(k)) 

        for (loop1 = 1; loop1 < n; loop1++) {
            diff = fabs(x_new[loop1] - x[loop1]); //Computing the error i.e.absolute(Xi(k+1)-Xi(k)) 		
            if (diff > max){
                max = diff; //updating the value of max
            }
        }

        for (loop1 = 0; loop1 < n; loop1++){
            x[loop1] = x_new[loop1]; //Updating the value of X for the next iteration
        }

        count++; ///Counting the no. of iterations

        fprintf(fp, "%d\t", count); //Writing the iteration no. to file

        for (loop1 = 0; loop1 < n; loop1++){
            fprintf(fp, "%f\t", x[loop1]); //Writing the value of Xi after each iteration into the file
        }
        fprintf(fp, "%f\n", max); //Writing the max. error in each iteration to the file

    } while (max > 0.000001); //For calculating the result with precision

    fprintf(fp, "\n\nSolutions: \n"); //Writing the obtained approximate solutions for the given 
    printf("\n\nSolutions: \n"); //Writing the obtained approximate solutions for the given 
    //simultaneous equations
    //check no solution
    flag = 1;
    for (loop1 = 0; loop1 < n && flag;loop1++){
    	if(x_new[loop1] != x_new[loop1]) {
    		flag = 0;
    	}
    }
    //display result in terminal and file
    for (loop1 = 0; loop1 < n && flag; loop1++){
        fprintf(fp, "X[%d] = %f\n", loop1 + 1, x_new[loop1]);
        printf("X[%d] = %f\n", loop1 + 1, x_new[loop1]);
    }
    if(!flag) {
        fprintf(fp, "No solution exits\n");
        printf("No solution exits\n");	
    }
    fclose(fp); //Closing the file
    return 0;
}