#include<stdio.h>
#include<string.h>

int main(){
	int i,j,stringSize,minSize,maxSize,len=2;
	stringSize=27;
	char sortedArr[54][stringSize];
	char current[stringSize],max[stringSize],min[stringSize];
	FILE *fp;
	fp = fopen("names.txt","r");
	strcpy(current, "start");
	minSize=1000;maxSize=1;i=0;
	while(i<54){
//		printf("%d %s %d\n",i,current,len);
		fgets(current, stringSize, fp);
		strcpy(sortedArr[i],current);
		//fscanf(fp,"%99[0-9a-zA-Z ]s\n",current);
		len=strlen(current);
		if(len>maxSize) {
			strcpy(max, current);
			maxSize = len;
		}
		else if(len<minSize) {
			strcpy(min, current);
			minSize = len;
		}
		i++;
	}
	printf("Maximum : \n\tName:%s\tSize:%d",max,maxSize);
	printf("\nMinimum : \n\tName:%s\tSize:%d\n",min,minSize);
	//Sorting the String Array
	i=0;j=0;
	int cmp;
	char temp[stringSize];
	char key[stringSize];
	for (i = 1; i < 54; i++)
	{
		strcpy(key,sortedArr[i]);
		j = i-1;
		while (j >= 0 && strcmp(key,sortedArr[j]) < 0)
		{
			strcpy(sortedArr[j+1],sortedArr[j]);
			j = j-1;
		}
		strcpy(sortedArr[j+1],key);
	}
		
	i = 0;
	fclose(fp);
	fp = fopen("sortedNames.txt","w");
	while(i<54){
		fprintf(fp,"%s",sortedArr[i]);
		i++;
	}
	fclose(fp);
	printf("\nSorted Names stored in sortedNames.txt\n\n");
	printf("Executing type sortedNames.txt\n\n");
	system("type sortedNames.txt");
	return 0;
}
