#include<stdio.h>
#include<time.h>
long counter1,counter2;
int fibRecInt(int a){
	counter1++;
	if(a<=1) return a;
	return fibRecInt(a-1)+fibRecInt(a-2);
}
long fibRecLong(long a){
	counter2++;
	if(a<=1) return a;
	return fibRecLong(a-1)+fibRecLong(a-2);
}

int main(){
int i=0;
int fibInt;
long fibLong;
clock_t start,end;
double cpu_time_Int,cpu_time_Long;
	while(i<48){
		start = clock();
		counter1=0;
		fibInt=fibRecInt(i);
		end = clock();
		cpu_time_Int = ((double) (end - start))/CLOCKS_PER_SEC;
		start = clock();
		counter2=0;
		fibLong=fibRecLong(i);
		end = clock();
		cpu_time_Long = ((double) (end - start))/CLOCKS_PER_SEC;
		printf("%d\t%d\t%ld\t%lf\t%ld\t%ld\t%lf\n",i+1,fibInt,counter1,cpu_time_Int,fibLong,counter2,cpu_time_Long);
		i++;
	}
}
