//Implementation of Jacobi Eigen Method in C language
//including libraries
#include<stdio.h>
#include<math.h>

//defining constants
#define epsilon 1E-4
#define MAX 30

//function to display array in the terminal
void dispArr(double arr[MAX][MAX],int n){
	//function to display array
	int j=0;
	int i=0;
	while(j<n){
		i = 0;
		while(i<n){
			//display in the terminal
			printf("%+lf\t",arr[i][j]);
			i++;
		}
		printf("\n");
		j++;
	}
}

//function to display array in output file
void printArr(double arr[MAX][MAX],int n, FILE* fp){
	//function to display array
	int j=0;
	int i=0;
	while(j<n){
		i = 0;
		while(i<n){
			//display in output file
			fprintf(fp,"%+lf\t",arr[i][j]);
			i++;
		}
		fprintf(fp,"\n");
		j++;
	}
}

//function to copy array
void copyArr(double src[MAX][MAX],double dst[MAX][MAX],int n){
	//function to copy array src to dst
	int j=0;
	int i=0;
	while(j<n){
		i = 0;
		while(i<n){
			//coping the array
			dst[i][j]=src[i][j];
			i++;
		}
		j++;
	}
}

//main function
int main(void){
	int i,j,max_i,max_j,n=4,flag;
	int counter = 1;
	//taking the matrix 
	double S[MAX][MAX] = {
		{4	,-30	,60	,-35},
		{-30	,300	,-675	,425},
		{40	,-675	,1620	,-1050},
		{-35	,420	,-1050	,700},
	};
	FILE* fp = fopen("../outputs/11.txt","w");
	fprintf(fp, "Jordan Eigen implementation in C language\n");
	double S_PREV[MAX][MAX];
	double max,theta,s,c;
	//iteration loop
	do {
		flag = 0;
		//coping array
		copyArr(S,S_PREV,n);
		//setting sentinel
		max = -1;
		//nested loops
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				//if conditon
				if( i != j && (fabs(S[i][j])>max)){
					max  = fabs(S[i][j]);
					max_i = i;
					max_j = j;
				}
			}
		}
		//setting theta
		if(fabs(S[max_i][max_j])-fabs(S[max_j][max_i]) < epsilon) theta = M_PI/4;
		else theta = .5*atan(2*S[max_i][max_j]/(S[max_j][max_j]-S[max_i][max_i]));
		//setting sine and cosine of theta
		s = sin(theta);
		c = cos(theta);
		//computing the max cell
		S[max_i][max_i] = c*c*S_PREV[max_i][max_i] - 2*s*c*S_PREV[max_i][max_j] + s*s*S_PREV[max_j][max_j];
		S[max_j][max_j] = s*s*S_PREV[max_i][max_i] + 2*s*c*S_PREV[max_i][max_j] + c*c*S_PREV[max_j][max_j];
		S[max_j][max_i] = S[max_i][max_j] = (c*c-s*s)*S_PREV[max_i][max_i] + s*c*(S_PREV[max_i][max_i] - S_PREV[max_j][max_j]);
		//for loop
		for (i = 0;i<n;i++){
			//if conditio 
			if( i != max_i && i != max_j ) {
				S[max_i][max_i] = S[i][max_i] = c*S_PREV[max_i][i] - s*S_PREV[max_j][j];
			}
		}
		//computing the cell
		for (i = 0;i<n;i++){
			if( i != max_i && i != max_j ) {
				S[max_i][max_i] = S[i][max_i] = s*S_PREV[max_i][i] + c*S_PREV[max_j][j];
			}
		}
		//computing the cell
		for (i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i != max_i && j != max_i && i != max_j && j != max_j) S[i][j] = S_PREV[i][j];
			}
		}
		//checking precision
		for (i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i != j && fabs(S[i][j])> epsilon ) {
					flag = 1;
					break;
				}
			}
		}
		//iteration count
		fprintf(fp,"\nIteration %d\n",counter++);
		printArr(S,n,fp);
	}
	while(flag);//loop terminator
	printf("After %d iterations Final Array:\n",counter-1);
	dispArr(S,n);
	//printing result
	fprintf(fp,"\nFinal Array:\n");
	printArr(S,n,fp);
	printf("\nEigen vectors are:\n");
	fprintf(fp,"\nEigen vectors are:\n");
	for(i=0;i<n;i++) {
		printf("%+lf\n",S[i][i]);
		fprintf(fp,"%+lf\n",S[i][i]);
	}
	//closing file pointer
	fclose(fp);
	return 0;
}