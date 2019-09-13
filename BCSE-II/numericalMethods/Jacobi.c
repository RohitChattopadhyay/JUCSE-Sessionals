//Implementation of Jacobi Elimination in C
//Including System libraries
#include<stdio.h> 
#include<math.h>
//defining constants
#define ESP 0.0001
//Given Equations 
#define X1(x2,x3) -1*((1-2*(x2)+3*(x3))/5)
#define X2(x1,x3) -1*((-2-3*(x1)+1*(x3))/9)
#define X3(x1,x2) -1*((-3+2*(x1)-1*(x2))/-7)

//main function
int main()
{
  FILE *fp;                                   //file pointer created
  fp=fopen("../outputs/10.txt","w");          //opening output file in write mode
  double x1=0,x2=0,x3=0,y1,y2,y3,error; 
  int i=0;     //intialising i with 0
  int j=1; //counter
  fprintf(fp,"Jacobi Elimination method implementation in C language\n\n");
  printf("Jacobi Elimination method implementation in C language\n\n");
  fprintf(fp,"\niter\tx1\t\tx2\t\tx3\t\tError\n"); // printing in file 
     // printing the value of x1,x2,x3 
  do
  {
   y1=X1(x2,x3);
   y2=X2(x1,x3);
   y3=X3(x1,x2);
   if(fabs(y1-x1)<ESP && fabs(y2-x2)<ESP && fabs(y3-x3)<ESP )  //checking the condition with precision
   {
     //printing result
     fprintf(fp,"\n\nSolutions\nx1 = %.3lf",y1);  // printing x1 in terminal
     fprintf(fp,"\n\nx2 = %.3lf",y2);  // printing x2 in terminal
     fprintf(fp,"\n\nx3 = %.3lf\n",y3);// printing x3 in terminal
     printf("\nSolutions\nx1 = %.3lf",y1);  // printing x1 in file
     printf("\n\nx2 = %.3lf",y2);  // printing x2 in file
     printf("\n\nx3 = %.3lf\n",y3);// printing x3 in file
     i = 1;
   }
   else
   {
     //iteration
     x1 = y1;
     x2 = y2;
     x3 = y3; 
     fprintf(fp,"\n%d\t%f\t%f\t%f\t%+f",j++,x1,x2,x3,error-x1);  //printing the value in file 
   }
   error=x1;
  }while(i != 1);
  fclose(fp);
}