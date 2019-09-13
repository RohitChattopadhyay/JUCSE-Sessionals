/* program to print the value of tan function from 0 to 360 */
#include<stdio.h>
#include<math.h>

float siner(float fx)  {                 /* user defined function siner is defined with a float type agrgument fx*/

		int in; float fterm, fsum, fmySin;
     
              fsum = 0;                                    /* fsum is assigned by the value 0 */
              in = 1; fterm = fx; fsum = fsum + fterm;
              while (fterm >= 0.0001 || fterm <= -0.0001) {
                      in = in + 1;
                      fterm = -fx * fx * fterm / ((2 * in - 2) * (2 * in - 1));
                      fsum = fsum + fterm;
                       };
                     	 fmySin = fsum;
                     	 //printf("%3d             %9.6f      " "\n", ix, fmySin);
              return fmySin;
    }

int main(){                                    /* beginning of function main*/
    int i, n,deg;                                /* varibles of integer tyes are declared */
    float x;
	deg=0;                                
	printf("deg\tmySin\t\tSine\t\tCos\t\tTan\n");       
 while(deg<361){    
    x=deg*3.14159/180;    					                       /* degrees are converted into radians */
	printf("%d\t%f\t%f\t%f\t%f\n",deg,siner(x),sin(x),cos(x),tan(x));
	deg=deg+15;                                                    /* degree variable is incremented by 15*/
	}
}                                                                  /* exit of main function */
