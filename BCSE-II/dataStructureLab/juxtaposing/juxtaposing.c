#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int nameSize=50;
	int nameLen;
	char name[nameSize];
	fgets(name, nameSize, stdin);
	nameLen=strlen(name)-1;// -1 for prevent printinf of 10(space)
	int sum[2][nameLen];
	int sumSplit[3][nameLen*3];
	int ASCII[nameLen];
	int i=0;
	while(i<nameLen){
		ASCII[i]=(int)name[i];
		if(i==nameLen/2) printf("\t+\t");
		if(ASCII[i]!=32)printf("%d",ASCII[i]);
		else ASCII[i]=0;
		i++;
	}
	printf("\n\n\n\n");

	
	printf("\n");
	return 0;
}
