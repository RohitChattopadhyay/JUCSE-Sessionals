#include<stdio.h>
#define Pi 3.1415926    /* defining the value of Pi to 3.1415926 */
int absolute(float val){            /* user defined function absolute is defined with a float type argument val */
	return val>0?val:val*-1;                        /* returning the value of value */ 
}
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
float cosine(float degInp) {           /* user defined function cosine is defined with a float type agrgument fx*/
	int loop, n,deg;
    float rad,sum,temp;
    sum=1;
    temp=1;
    for(loop=1;temp>0.0000001 || temp<-0.0000001;loop++){         
        temp=temp*(-1)*degInp*degInp/(2*loop*(2*loop-1));
        sum+=temp;
    }     
    return sum;                                    /*returning sum*/
    }

int main(void){                             /* beggining of main function */
	float fRow,fExtent;                     /* float type variable are declared */
    int iCol;                               /* integer type varibale is declared */
    fRow=0;iCol=0;
    fExtent=30;
    while(fRow<31){
       iCol=0;
    while(iCol<91){
            if(iCol%45==0 & fRow==15){
				printf("+");
			}
			else if(iCol==0){               /* printing the y axis*/
				printf("|");
			}
			else if((absolute(fExtent*(((siner((Pi/90)*iCol*2)))-((15-fRow)/15)))<0.0000005)){
				printf("*");
			}
			else if((absolute(fExtent*(((cosine((Pi/90)*iCol*2)))-((15-fRow)/15)))<0.0000005)){
				printf(".");
			}
			else if(fRow==15){printf("-");    /* printing the x axis  */ 
			}
			else {
				printf(" ");
			}
			iCol++;                           /* iCol is incremented by 1*/ 
		}
		printf("\n");                       /* printing the value of new line */
		fRow++;                            /* fRow is incremented by 1 */ 
		}
}                                          /* exit of function main */ 

