#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
int main()
{
	int i,num,j;
	int max=60000;
	FILE* fp;
	int arr[max];
	srand(time(NULL));
	fp = fopen("randomNumbers.csv","w");
	
	for(i=0;i<max;i++){
		arr[i]=i+1;	
	}
	shuffle(arr,max);
	for(i=0;i<max;i++) fprintf(fp,"%d \n",arr[i]);
	printf("Saved in file\n");
}

