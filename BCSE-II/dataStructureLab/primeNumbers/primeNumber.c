//unsigned long long int num
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
	
	FILE* fp;
	fp = fopen("primeRemainder.txt","w");
	unsigned long long int arr[10];
	int prime[3];
	int a,b,c,d,e,f,g;
	srand(time(NULL));
	int i=0;
	printf("Enter the Prime Numbers\n");
	while(i<3){
		scanf("%d",&prime[i]);
		i++;
	}
	fprintf(fp,"Prime->\t\t%d\t%d\t%d\n",prime[0],prime[1],prime[2]);
	//Generating Large Random Numbers
	i=0;
	while(i<10){
		arr[i]= abs((rand()+RAND_MAX)*(rand()+RAND_MAX)*(rand()+RAND_MAX)*RAND_MAX*RAND_MAX*RAND_MAX*RAND_MAX*RAND_MAX)*2147483647;
		i++;
	}
	int j=0;
	while(j<10){
		i=0;
		fprintf(fp,"%llu",arr[j]);
		while(i<3){
			fprintf(fp,"\t%d",arr[j]%prime[i]);
			i++;
		}
		fprintf(fp,"\n");
		j++;
	}
	srand(time(NULL));
	fclose(fp);
	printf("\nSaved to File\n");
}



