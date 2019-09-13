#include<stdio.h>
#include<time.h>

int switcher=0;
int fibInt=0;
long fibLong=0;
int fibonacciInt(int a){
	if(fibInt==fibLong) switcher = 0;
	else switcher=1;
	clock_t start,end;
	double cpu_time_used;
	int next,i=0;
	printf("%d\t ",a);
	start = clock();
	next=a;
	if(a<2) {
		printf("1\t%lf\t",cpu_time_used);
		return 0 ;
	}
	while(a>1){
		a--;
		next*=a;
	}
	end = clock();
	cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
	if(1)	printf("%d\t%lf\t",next,cpu_time_used);
}
int fibonacciLong(long a){
	clock_t start,end;
	double cpu_time_used;
	long next,i=0;
	start = clock();
	next=a;
	if(a<2) {
		printf("1\t%lf\n",cpu_time_used);
		return 0;
	}
	while(a>1){
		a--;
		next*=a;
	}
	end = clock();
	cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
	if(1)	printf("%ld\t%lf\n",next,cpu_time_used);
}

int main(){
int i=-1;
	while(i<40){
		i++;
		fibonacciInt(i);
		fibonacciLong(i);
	}
}
