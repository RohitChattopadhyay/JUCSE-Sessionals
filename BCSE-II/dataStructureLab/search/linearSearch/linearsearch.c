#include<stdio.h>
void linearSearchInt(int size)
{
	int array[size];
	int i,search;
	//Requesting elements
	printf("Please enter the Array elements (Integer)\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	//Requesting Search String
	printf("Integer to be searched:");
	scanf("%d",&search);
	//Searching Strings
	for(i=0;i<size;i++)
	{
		if(array[i]==search)
			break;
    }
    //Printing Result
	if(i<size) printf("Integer %d found at index %d\n", search, i+1);
	else printf("Search Integer not found!\n");
}
void linearSearchFloat(int size)
{
	//Function for Float
    double array[size],search;
	int i;
	//Requesting elements
	printf("Please enter the Array elements (Float)\n");
	for(i=0;i<size;i++)
	{
		scanf("%lf",&array[i]);
	}
	//Requesting Search String
	printf("Float to be searched:");
	scanf("%lf",&search);
	//Searching in loop
	for(i=0;i<size;i++)
	{
		if(array[i]==search)
			break;
    }
    //printing result
	if(i<size) printf("Float %lf found at index %d\n", search, i+1);
	else printf("Search float not found!\n");
}
void linearSearchString (int arraySize,int maxSize) {
	int i;
	char Array[arraySize][maxSize];
	printf("Please enter the Array elements (String)\n");
	for(i=0;i<arraySize;i++){
		scanf("%s",Array[i]);
	}
	char searchKey[maxSize];
	//Requesting Search String		
	printf("Enter the Search String (Case Sensetive)\n");
	scanf("%s",searchKey);
	int flag=0;
	//Searching in loop
	for (i = 0; i < arraySize; ++i) {
		if (strcmp(Array[i], searchKey) == 0) {
			flag=1;
			break;
		}
	}
	//printing result
    if (flag != 1) {
        printf("Search string not found!\n");
    }
    else {
        printf("String %s found at index %d\n", searchKey, i+1);
    }
}

int main()
{
	int size,method,maxSize;
    printf("Select method:\n\n\t1->Int\n\t2->Float\n\t3->String\n");
	while(scanf("%d",&method)){
		if(method<1 || method>3) {
			printf("Invalid method\nSelect method:\n\n\t1->Int\n\t2->Float\n\t3->String\n");
			continue;
		}//error pop for bad input
		printf("Enter Size of Data Set\n");
		scanf("%d",&size);//taking size
		while(size<2) {
			printf("Enter Size of Data Set\n");
			scanf("%d",&size);		
		}
		switch(method){
			case 1:
				linearSearchInt(size);
				break;
			case 2:
				linearSearchFloat(size);
				break;
			case 3:
				printf("Enter Maximum length of elements in Data Set\n");
				scanf("%d",&maxSize);
				linearSearchString(size,maxSize);
				break;						
		}
		printf("\nSelect method:\n\n\t1->Int\n\t2->Float\n\t3->String\n");
	}
}
