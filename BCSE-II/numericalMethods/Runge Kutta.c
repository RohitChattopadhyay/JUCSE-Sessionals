//Implementation of Runge Kutta in C language
//Including libraries
#include<stdio.h>
//defining global constant
#define EPS 1E-6

//function to return y-x
double f(double x,double y){
    return y-x;   // function given y-x
}

//main function
int main(){   //beginning of main function  
  FILE *fp=fopen("../outputs/23.txt","w");       // writing in file 
  double x,y,x0,y0,xn,k1,k2,h; // declaring and intialising the DOUBLE variables
  int iter = 1;     // declaring and intialising the INT variables
  printf("Please enter the value of x:\t");
  scanf("%lf",&x0);                          // taking input from the user 
  printf("Please enter the value of y:\t");
  scanf("%lf",&y0);                        // taking input fhttps://www.codewithc.com/c-program-for-lu-factorization/rom the user 
  printf("Please enter the final value of x:\t");
  scanf("%lf",&xn);                      // taking input from the user 
  printf("Please enter the value of h:\t");
  scanf("%lf",&h);     // taking input from the user 
   // printing in the file 
  fprintf(fp, "Implementation of Runge Kutta in C language\n\n");
  fprintf(fp,"%12s%12s%12s%12s%12s\n", "Iteration", "x", "k1", "k2", "y");
  fprintf(fp,"%12d%12lf%12s%12s%12lf\n", iter, x, "", "", y);
  x=x0;
  y=y0;
  while (x<xn -EPS){
      // calculating the values of k1,k2 and y1
     k1=h*f(x,y);
     k2=h*f(x+h,y+k1);
     y=y+0.5*(k1+k2);
     x+=h; //incrementing the value of h
     fprintf(fp,"%12d%12lf%12lf%12lf%12lf\n", ++iter, x, k1, k2, y); // printing the output in file 
 }// end of loop 
 fprintf(fp, "\nResult\n\tf(%lf) = %lf\n",x,y );
 printf("\nResult\n\tf(%lf) = %lf\n",x,y );
 fclose(fp); //closing the file pointer
}//end of main function 
