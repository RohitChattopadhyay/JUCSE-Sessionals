//Implementation of Regula Falsi in C language
//Including libraries
#include<stdio.h>
#include<math.h>
//Defining universal constants
#define e 2.718281828
//Function for returning value f(x)
double f(double x){  
  return pow(e,-x)-x;  // function is e^(-x)=x
}
int main(){
  double lower,higher,middle,prevroot; //intiating double variables
  int iteration=1; 				//intiating iteration counter
  //taking user inputs
  printf("Implementation of Regula Falsi in C language\n\n");
  printf("Enter the lower value : ");
  scanf("%lf",&lower);  //scanning Lower of interval
  printf("Enter the higher value : ");
  scanf("%lf",&higher); //scanning Upper of interval
 //Checking bad inputs from user
  while(f(higher)*f(lower)>=0){
    printf("Error");
    printf("Enter the lower value :");
    scanf("%lf",&lower); //scanning Lower of interval again
    printf("Enter the higher value :");
    scanf("%lf",&higher);       //scanning Upper of interval again
  }
  //File Handling
  FILE *fp; 				//intiating File Pointer
  fp=fopen("../outputs/22.txt","w");
  fprintf(fp, "Implementation of Regula Falsi method in C\n\nLower = %lf\tHigher = %lf\n\n",lower,higher );
  //creating table header
  //fprintf(outputFile,"Iteration\ta\t\tb\t\t(a+b)/2\t\tf((a+b)/2)\tf(a)*f(a+b)/2)\tRelative Error\n\n");
  fprintf(fp,"Iteration\ta\t\tb\t\tf(c)\t\tRelative Error\n\n");
  while(fabs(higher-lower)>0.000001){
     prevroot=middle ; //saving previous root for calculation of relative error
     middle=(lower*f(higher)-higher*f(lower))/(f(higher)-f(lower));
     //creating table rows
     fprintf(fp,"%d\t\t%lf\t%lf\t%lf\t%+lf\n",iteration,lower,higher,f(middle),fabs(prevroot-middle)/middle);
     if(fabs(f(middle))<0.000001) break;
     else if(f(middle)*f(lower)<0){  //checking on which half middle term lies
          higher=middle;
     }
     else 
        lower=middle;
 iteration++;
 }
 fprintf(fp,"\nResult\n\tThe value of root is %lf\n",middle); //printing the root in output file
 fclose(fp); //closing file pointer
 //output messages on terminal
 printf("The value of root is %lf\nTotal Iterations: %d\n",middle,iteration);
 return 0;
}
