//Implementation of Newton Ralphson method in C language
//Including libraries
#include<stdio.h>
#include<math.h>
//defining universal constants
#define e 2.718281828

//function for returning function value
double f(double x){
   return pow(e,-x)-x; // function is y=e^(-x)-x
}
//function for returning derivation of function value
double df(double x){
  return -1*pow(e,-x)-1; // derivative function is y'=-e^(-x)-x
}
//main function
int main(){
  double decrement=1,predecrement,position;
  position = 0;
  int iteration=1;
  FILE *fp;   //File Handling
  fp=fopen("../outputs/19.txt","w");
  //creating table header
  printf("Implementation of Newton Ralphson Method in C language\n\n");
  fprintf(fp,"Implementation of Newton Ralphson Method in C language\n\nIteration\tx\t\tf(x)\t\tf'(x)\t\tf(x)/f'(x)\tRelative Error\tOrder of Convergence(n)\n\n");
  while(fabs(decrement)>0.000001){
     predecrement=decrement;
     decrement=f(position)/df(position);
     if(iteration == 1) 
	fprintf(fp,"%d\t\t%lf\t%lf\t%lf\t%lf\t\n",iteration,position,f(position),df(position),decrement);
     else		
        fprintf(fp,"%d\t\t%lf\t%lf\t%lf\t%lf\t%+lf\t%lf\n",iteration,position,f(position),df(position),decrement,decrement/position,fabs(log(fabs(decrement))/log(fabs(predecrement))));
		//Changing the position of x
		position-=decrement;
		iteration++;
 }
 fprintf(fp,"\nThe value of root : %lf\n",position); //printing the root in output file
 fclose(fp); //closing file pointer
 //printing result on terminal
 printf("The value of root : %lf\nTotal Iterations: %d\n",position,iteration-1);
 return 0;
}
