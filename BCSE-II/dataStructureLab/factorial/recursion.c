#include<stdio.h>
#include<time.h>
int factRecInt(int a){
	if(a<=1) return 1;
	return factRecInt(a-1)*a;
}
long factRecLong(long a){
	if(a<=1) return 1;
	return factRecLong(a-1)*a;
}

int main(){
int i=0;
int factInt;
long factLong;
clock_t start,end;
double cpu_time_Int,cpu_time_Long;
	while(i<48){
		start = clock();
		factInt=factRecInt(i);
		end = clock();
		cpu_time_Int = ((double) (end - start))/CLOCKS_PER_SEC;
		start = clock();
		factLong=factRecLong(i);
		end = clock();
		cpu_time_Long = ((double) (end - start))/CLOCKS_PER_SEC;
		printf("%d\t%d\t%lf\t%ld\t%lf\n",i,factInt,cpu_time_Int,factLong,cpu_time_Long);
		i++;
	}
}
