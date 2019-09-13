 
#include<stdio.h>
float func(float x){          /*user defined function func is created with floating argument*/ 
	return x*x*x*x*x*x-729;    
}

float derFunc(float x){      /*user defined function derfunc is created with floating argument*/ 
	return 6*x*x*x*x*x;       /* returing the derivative of x^6 = 729 */
}

float main(){           /* beginning of main function */
	float x=729;           /* x is intialised by 729 */
	while ((func(x)/derFunc(x))>0.00001 || (func(x)/derFunc(x)<-0.00001)){
		x-=func(x)/derFunc(x);                 /* x= x- func(x)/derfunc(x)*/ 
		
	}
	printf("%.3f\n",x);        /*printing the value of x*/ 
	return 0;
}                              /* end of main function*/ 

    

