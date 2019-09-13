#include<stdio.h>
#include<string.h>
void binarySearchInt(int size)
{
	int array[size];
	int i,j,search;
	//Requesting elements
	printf("Please enter the Array elements (Integer)\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	//Sorting the Array
	
	for (i = 0; i < size-1; i++){
		for (j = 0; j < size-i-1; j++){
			if (array[j] > array[j+1]){
				search = array[j];
				array[j] = array[j+1];
				array[j+1] = search;
			}	
		}
	}
	
	//Requesting Search String
	printf("Integer to be searched:");
	scanf("%d",&search);
	//Searching Strings
	int flag=0;
	int r=size+1;
	int l=0;
	int m;
    while (l <= r)
    {
        int m = l + (r-l)/2;
 
        // Check if search is present at mid
        if (array[m] == search){
            flag=1;
            break;
			}
 
        // If search greater, ignore left half
        if (array[m] < search)
            l = m + 1;
 
        // If search is smaller, ignore right half
        else
            r = m - 1;
    }
    //Printing Result
	if(flag) printf("Integer %d found in given set.\n", search);
	else printf("Search Integer not found!\n");
}
void binarySearchFloat(int size)
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
	//Sorting the Array
	int j;
	for (i = 0; i < size-1; i++){
		for (j = 0; j < size-i-1; j++){
			if (array[j] > array[j+1]){
				search = array[j];
				array[j] = array[j+1];
				array[j+1] = search;
			}	
		}
	}

	//Requesting Search String
	printf("Float to be searched:");
	scanf("%lf",&search);

	//Searching Strings
	int flag=0;
	int r=size+1;
	int l=0;
	int m;
    while (l <= r)
    {
        int m = l + (r-l)/2;
 
        // Check if search is present at mid
        if (array[m] == search){
            flag=1;
            break;
        }
 
        // If search greater, ignore left half
        if (array[m] < search)
            l = m + 1;
 
        // If search is smaller, ignore right half
        else
            r = m - 1;
    }

    //printing result
	if(flag) printf("Float %lf found in given set.\n", search);
	else printf("Search float not found!\n");
}
void binarySearchString (int arraySize,int maxSize) {
	int i;
	char Array[arraySize][maxSize];
	printf("Please enter the Array elements (String)\n");
	for(i=0;i<arraySize;i++){
		scanf("%s",Array[i]);
	}
	char searchKey[maxSize];
		//Sorting the Array
	int j;
	for (i = 0; i < arraySize-1; i++){
		for (j = 0; j < arraySize-i-1; j++){
			if (strcmp(Array[j],Array[j+1])){
				strcpy(searchKey,Array[j]);
				strcpy(Array[j],Array[j+1]);
				strcpy(Array[j+1],searchKey);
			}	
		}
	}
	//Requesting Search String		
	printf("Enter the Search String (Case Sensetive)\n");
	scanf("%s",searchKey);
	
	//Searching Strings
	int flag=0;
	int r=arraySize+1;
	int l=0;
	int m;
    while (l <= r)
    {
        int m = l + (r-l)/2;
 
        // Check if search is present at mid
        if (strcmp(Array[m],searchKey)==0){
            flag=1;
            break;
        }
 
        // If search greater, ignore left half
        if (strcmp(Array[m],searchKey)<0)
            l = m + 1;
 
        // If search is smaller, ignore right half
        else
            r = m - 1;
    }
	//printing result
    if (flag != 1) {
        printf("Search string not found!\n");
    }
    else {
        printf("String %s found in given set.\n", searchKey);
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
				binarySearchInt(size);
				break;
			case 2:
				binarySearchFloat(size);
				break;
			case 3:
				printf("Enter Maximum length of elements in Data Set\n");
				scanf("%d",&maxSize);
				binarySearchString(size,maxSize);
				break;						
		}
		printf("\nSelect method:\n\n\t1->Int\n\t2->Float\n\t3->String\n");
	}
}
