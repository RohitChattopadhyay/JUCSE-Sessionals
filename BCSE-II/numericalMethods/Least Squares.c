//Implementation of Least Square Fitting Method in C language
//including libraries
#include<stdio.h>
#include<math.h>

//main function
int main()
{
    FILE *fp=fopen("../outputs/12.txt","w");
    float x[100],y[100],x_sq[100],xy[100],sumx,sumy,sumxy,sumxsq,a,b;
    sumx=sumy=sumxy,sumxsq=0;
    int n,i;
    printf("Please enter number of Pairs of (Xi,Yi):\t");
    scanf("%d",&n);
    fprintf(fp,"\nImplementation of Least Square Fitting Method in C language\n\nPairs of xi,yi: %d\n\nIter\tXi\t\tYi\n\n",n);
    //Taking the inputs from user
    for(i=0;i<n;i++)
    {
    	printf("Please Enter X%d Y%d :\t",i+1,i+1);
        scanf("%f %f",&x[i],&y[i]);
        fprintf(fp,"%d\t%f\t%f\n",i+1,x[i],y[i]);
        sumx=sumx+x[i];//Computing the sum of all the Xi
        sumy=sumy+y[i];//Computing the sum of all the Yi
        sumxy=sumxy+x[i]*y[i];//Computing the sum of all the Xi*Yi
        sumxsq=sumxsq+x[i]*x[i];//Computing the sum of all the Xi*Xi
        x_sq[i]=x[i]*x[i];
        xy[i]=x[i]*y[i];        
    }
    //Writing the table to the output file
    fprintf(fp,"\nIter.\tXi\t\tYi\t\tXiYi\t\tXi^2\n\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t%f\t%f\t%f\t%f\n",i+1,x[i],y[i],xy[i],x_sq[i]);
    }
    fprintf(fp,"\nSummation Xi= %f\n",sumx);
    fprintf(fp,"\nSummation Yi= %f\n",sumy);
    fprintf(fp,"\nSummation XiYi= %f\n",sumxy);
    fprintf(fp,"\nSummation Xi^2= %f\n",sumxsq);

    //Computing coefficients of A and B in Y=A + BX
    a=(sumy*sumxsq-sumx*sumxy)/(n*sumxsq-sumx*sumx);
    b=(n*sumxy-sumx*sumy)/(n*sumxsq-sumx*sumx);
    
    fprintf(fp,"\nObtained Curve is: Y = %f + %fX\n",b,a);
    printf("\nObtained Curve is: Y = %fX + %f\n",b,a);

    fclose(fp);
    return 0;   
}