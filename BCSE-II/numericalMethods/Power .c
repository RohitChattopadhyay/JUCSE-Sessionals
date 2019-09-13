//Implementation of Power Method in C language
//Including libraries
#include <stdio.h>
#include <math.h>

//main function
int main()
{
    FILE *fp;
    fp=fopen("../outputs/21.txt","w");//Create a new output file to store the operations
    int n,loop1,loop2,cnt=0;
    fprintf(fp, "Implementation of Power Method in C language\n\n");
    //Accept the order of the matrix
    printf("Please enter order of the square matrix: ");
    scanf("%d",&n);
    
    float arr[n][n];float X[n],Y[n];
    float lambda,lambda1,diff;
    //Accept from console and write the matrix into the output file
    printf("Enter the matrix: \n");
    fprintf(fp,"Original Matrix: \n");
    for(loop1=0;loop1<n;loop1++)
    {
        for(loop2=0;loop2<n;loop2++)
        {
            printf("M[%d][%d]: ",loop1+1,loop2+1);
            scanf("%f",&arr[loop1][loop2]);//Accept data from console
            fprintf(fp,"%f\t",arr[loop1][loop2]);//Write data into the file
        }
        fprintf(fp,"\n");//Print a new line in the file
    }
    
    //Assign a initial approximation to the eigen vector
    for(loop1=0;loop1<n;loop1++)
        X[loop1]=1;
    lambda=1;//Initial Approximation for eigen value
    fprintf(fp,"\nStep %d\n\tC%d :  %f\n\tEigen Vector:\t ",++cnt,cnt,lambda1);
    for(loop1=0;loop1<n;loop1++)
        fprintf(fp,"%f\t",X[loop1]);
        fprintf(fp,"\n");
    do
    {
        float max;
        //Computing the result of A * Xi=Yi
        for(loop1=0;loop1<n;loop1++)
        {
            Y[loop1]=0;
            for(loop2=0;loop2<n;loop2++)
                Y[loop1]+=X[loop2]*arr[loop1][loop2];//Compute each element of Yi
        }
        max=Y[loop1];//Taking the first value as approximation for maximum
        //Loop to find the maximum value in Yi
        for(loop1=0;loop1<n;loop1++)
        {
            if(Y[loop1]>max)
                max=Y[loop1];
        }
        
        //Creating the new Xi
        for(loop1=0;loop1<n;loop1++)
            X[loop1]=Y[loop1]/max;
        lambda1=max;//Assigning the maximum value as the currently approximated max. eigen value
        
        //Writing the obtained eigen value and eigen vector to the output file
        fprintf(fp,"\nStep %d\n\tC%d :  %f\n\tEigen Vector:\t ",++cnt,cnt,lambda1);
        for(loop1=0;loop1<n;loop1++)
            fprintf(fp,"%f\t",X[loop1]);
            fprintf(fp,"\n");
            
        diff=fabs(lambda-lambda1);//Compute the error in the consecutive obtained eigen values
        lambda=lambda1;//Assign the obtained eigen value as the old approx. for next iteration
        
    }while(diff>0.000001);//Compute the eigen value correct upto 5th decimal place
    
    fprintf(fp,"\n\nResult\n\tLargest Eigen value: %f\n",lambda);//Write obtained result to the output file
    printf("\n\nResult\n\tLargest Eigen value: %f\n",lambda);//Write obtained result to the terminal
    fclose(fp);//Close the file
    return 0;
}