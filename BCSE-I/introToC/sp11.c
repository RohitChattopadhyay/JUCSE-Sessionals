/*program to find A x B x C, where A={1,2,3,4,5}, B={1,2,3} and C={1,2,3,4}. */
#include<stdio.h> 
int main()
{                                                /*begnning of main function  */
	int loop1Var,loop2Var,loop3Var;              /*integer type variables are declared*/
	 printf("{ A\tB\tC }\n");
	for(loop1Var=loop2Var=loop3Var=1;loop1Var<6;loop3Var<4 ? loop3Var++ :(loop2Var<3?(loop2Var++,loop3Var=1):(loop1Var++,loop2Var=loop3Var=1) ))
	{           /*begnning of loop*/
				printf("{ %d\t%d\t%d }\n",loop1Var,loop2Var,loop3Var);    /*printing the following vaiables*/
	}                              /*end of loop*/
}                                   /*end of main function */

