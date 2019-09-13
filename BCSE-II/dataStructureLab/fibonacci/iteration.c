#include<stdio.h>
#include<time.h>
int fibonacciInt(int a){
	clock_t start,end;
	double cpu_time_used;
	int t1=0;int t2=1;
	int next,i=4;
	printf("%d\t: ",a);
	next=t1+t2;
	start = clock();
	if(a==1) {
		printf("0\t%lf\t",cpu_time_used);
		return 0 ;
	}
	while(i<=a){
		i++;
		t1=t2;
		t2=next;
		next = t1+t2;
	}
	end = clock();
	cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("%d\t%lf\t",next,cpu_time_used);
}
int fibonacciLong(long a){
	clock_t start,end;
	double cpu_time_used;
	long t1=0;long t2=1;
	long next,i=4;
	next=t1+t2;
	start = clock();
	if(a==1) {
		printf("0\t%lf\n",cpu_time_used);
		return 0;
	}
	while(i<=a){
		i++;
		t1=t2;
		t2=next;
		next = t1+t2;
	}
	end = clock();
	cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("%ld\t%lf\n",next,cpu_time_used);
}

int main(){
int i=0;
	while(i<300){
		i++;
		fibonacciInt(i);
		fibonacciLong(i);
	}
}
