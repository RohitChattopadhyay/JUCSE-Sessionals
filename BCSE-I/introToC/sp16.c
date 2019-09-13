/*Continue taking integer inputs into an integer array through the terminal unitil 0/’X’/’x’ is not entered. As one does not 
know the number of inputs, allocate the integer array dynamically, i.e. it grows as the number of inputs increases. 
Sort the integer array and find the mean, median and mode of the array.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void insertion_sort(int m, int *array) {  /*user defined function insertion_sort is defined which sort the given array */
         int t, k,i;
         array[0] = INT_MIN;
         for (i = 2; i <= m - 1; i = 1 + i) {
               t = array[i]; k = i - 1;
               while (t < array[k]) { array[k+1] = array[k]; k = k -1;};
               array[k + 1] = t;
         };
}

int main(void){            /*beginning of main function*/
	int inp,i2,i=1;
	float mean=0;
	int *arr;
	arr= malloc(1*sizeof(int));       /*allocate the integer array dynamically*/
	while(scanf("%d",&inp)){          /*taking input from user*/
		if(inp==0) break;
		arr= realloc(arr,sizeof(int));
		arr[i]= inp;
		mean = mean+(float)inp;   /*calculating the mean*/
		i++;
	} 
	insertion_sort(i,arr);    /*calling the function insertion sort*/
	i2=1;
	while(i2<i){
		printf("%d\t%d\n",i2,(arr[i2]));
		i2++;                               /*printing the sorted array*/
	}

	int MaxCount=0,Count=0;         /*maxcount and count are intialised with 0 and i2 with 1*/
	i2=1;
	while(i2<i){                        /*calculating mode*/
		if(arr[i2]==arr[i2+1]) {
			Count++;
			if(Count>MaxCount) {
				inp=arr[i2];
				MaxCount=Count;	
			}
		}
		else Count=0;
		i2++;
	}	                                                	 /*printing the mean median mode of a sorted array*/
	printf("Array is printed\nMean:\t%f\nMedian:\t%d\nMode:\t%d",(mean/(i-1)),i%2==0?(arr[i/2]+arr[i/2+1])/2:arr[(i+1)/2],inp);
}	          /*end of main function*/
