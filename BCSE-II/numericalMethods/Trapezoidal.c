//Implementation of Trapezoidal Method  in C language
//Including libraries
#include<stdio.h>
#include<math.h>
//function to be integrated
double f(double x){         //Computing the value of function
    return 1/(1+(x*x));
}
int main(){
 FILE *fp=fopen("../outputs/26.txt","w");
 double lower,higher,h,s0,s1,I1,I0;
 int n,ctr=1,i;
 printf("Please enter the lower limit: ");    //Accept the lower limit
 scanf("%lf",&lower);
 printf("Please enter the upper limit: "); //Accept the upper limit
 scanf("%lf",&higher);
 fprintf(fp,"Implementation of Simpson 1/3 Method in C language\n\nIntegrating 1/(1+x^2)\n\n");
 fprintf(fp,"Lower Limit= %f \tUpper Limit= %f\n\n",lower,higher);
 fprintf(fp,"Step\tWidth\t\tIntegration\tError\n\n");
 h=higher-lower;  //Computing the width of the interval
 s1=0;
 s0=f(lower)+f(higher); //Computing the Integration by using the formula for a trapezium
 I1=s0*h/2;
 n=1;
 //Displaying the first iteration in the output file
 fprintf(fp,"%d\t%f\t%f\t%f\n",ctr++,h,I1,I1);
 do{
   s1=0;
   h=h/2; //Reducing the width size of interval by half
   I0=I1;
   for(i=1;i<2*n;i+=2){
     s1=s1+f(lower+i*h); //Calculating the values of function at points which are previously not considered
   }
   s0=s0+2*s1;
   I1=s0*h/2;  //Computing the Trapezoidal integration value
   n=n*2; //Increasing the no. of intervals
   fprintf(fp,"%d\t%f\t%f\t%f\n",ctr++,h,I1,I1-I0);
 }while(fabs(I1-I0)>0.000001); //To compute the integration value accurate upto 6 decimal places
 fprintf(fp,"\nResult\n\tApproximate value of integration is %lf\n",I1);//Writing the final value obtained into the output file
 printf("\nResult\n\tApproximate value of integration is %lf\n",I1);//Writing the final value obtained into terminal
 fclose(fp);//Closing the file
 return 0;    
}
