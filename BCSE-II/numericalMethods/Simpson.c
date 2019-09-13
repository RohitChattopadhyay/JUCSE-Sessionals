//Implementation of Simpson 1/3 in C language
//Including libraries
#include<stdio.h>
#include<math.h>


//function to be analysed
double f(double x){   //Computing the value of function
  return 1/(1+(x*x));
}
//main function
int main(){
  double lower,higher,h,s0,s1,I0,I1,err;
  FILE *fp=fopen("../outputs/25.txt","w");
  printf("Please enter the lower limit: "); //Accept the lower limit
  scanf("%lf",&lower);
  printf("Please enter upper limit: ");  //Accept the upper limit
  scanf("%lf",&higher);
  h=(higher-lower)/2; //Computing the width of the interval
  s1=4*f(lower+h);
  s0=f(lower)+f(higher); 
  I0=(s0+s1)*h/3;  //Computing the Integration by formula A=h*{f(xi-1)+4*f(xi)+f(x+i)}/3
  int n=2,i;
  fprintf(fp,"Implementation of Simpson 1/3 Method in C language\n\nIntegrating 1/(1+x^2)\n\n");
  fprintf(fp,"Lower Limit = %f \tUpper Limit = %f\n\n",lower,higher);
  int cnt=1;
  fprintf(fp,"Step\tWidth\t\tIntegration\tError\n\n");
  //Displaying the first iteration in the output file
  fprintf(fp,"%d\t%f\t%f\t%f\n",cnt,h,I0,I1);
  do{
    s1=0; //Loop to calculate the sum by adding weights to function value at each xi
    h=h/2; //Reducing the width of each interval to half
    for(i=1;i<2*n;i++){
      if(i%2!=0)
        s1=s1+4*f(lower+i*h); //Computing the integration value
      else
        s1=s1+2*f(lower+i*h);
    }
    I1=(s0+s1)*h/3;
    n=n*2;//increasing the no. of intervals for the next iteration
    err=I1-I0;
    cnt++;
    fprintf(fp,"%d\t%f\t%f\t%f\n",cnt,h,I1,err); //print row
    I0=I1;
  }while(fabs(err)>0.000001); //To compute the integration value accurate upto 6 decimal places
  fprintf(fp,"\n\nApproximate value of integration is %lf\n",I1);//Writing the final value obtained into the output file
  printf("\nResult\n\tApproximate value of integration is %lf\n",I1);//Writing the final value obtained into the output file
  fclose(fp);//Closing the file
  return 0;   
}
