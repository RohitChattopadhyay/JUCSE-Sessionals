#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define Pi 3.1415926
#define g 9.81
float modder(float var){
	return var>0?var:-1*var;
}
int main(void){
	
	int vel;float ang,hit=0;
	float cliff,fRow,root1,root2;
	int iCol,pig,iColLim;
	float D,fExtent,initial;
	fRow=0;iCol=0;
	srand (time(NULL));
	cliff=rand()%20;
	pig=rand()%100;
	printf("The bird is at height %fm, and a pig is %dm away from the bottom of cliff. Enter speed\n",cliff,pig);
	scanf("%d",&vel);
	printf("Enter Angle\n");
	scanf("%f",&ang);
	ang*=Pi/180;
	fExtent=25;
	float H,R;
	H=modder(vel*sin(ang));
	H*=H/(2*g);
	
	if(H<cliff){
		printf("You MISS");
		return 0;
	}	
	R=modder(vel*vel*sin(2*ang))/g;
	
	
	iColLim=pig>R?pig:R;
	initial=(tan(ang)+sqrt(tan(ang)*tan(ang)-(4*g*(cliff))/(2*vel*vel*cos(ang)*cos(ang))))/(g/(vel*vel*cos(ang)*cos(ang)));
	while(fRow<(H+1)){
		iCol=initial;
		while(iCol<(iColLim+4)){
			D=tan(ang)*tan(ang)-(4*g*(H-fRow))/(2*vel*vel*cos(ang)*cos(ang));
			if(D>0){
				root1=(tan(ang)+sqrt(D))/(g/(vel*vel*cos(ang)*cos(ang)));
				root2=(tan(ang)-sqrt(D))/(g/(vel*vel*cos(ang)*cos(ang)));
			}
			else{
				root1=-1;
				root2=-1;
			}

			if(fRow==((int)H+1) && iCol==pig){
				printf("%c",219);
				break;
			}
			else if((modder(fExtent*(root1-iCol))<15) || (modder(fExtent*(root2-iCol))<15) ){
				printf("*");
			}
			else {
				printf(" ");
			}
			iCol++;
		}
		printf("\n");
		fRow++;
		sleep(1);
		}
		if(modder(((tan(ang)-sqrt(tan(ang)*tan(ang)-(4*g*(0))/(2*vel*vel*cos(ang)*cos(ang))))/(g/(vel*vel*cos(ang)*cos(ang))))-pig)<2 || modder(((tan(ang)+sqrt(tan(ang)*tan(ang)-(4*g*(0))/(2*vel*vel*cos(ang)*cos(ang))))/(g/(vel*vel*cos(ang)*cos(ang))))-pig)<2) printf("You HIT\n");
		else printf("You MISS\n");
}

