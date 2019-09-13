//implementation of Bairstow method in C language

//including libraries
#include<stdio.h>
#include<math.h>

//main function
int main()
{
	int n;
	//taking user input from user
	printf("Enter Degree of polynomial\n");
	scanf("%d",&n);
	n++;
	int i,j;
	//opening File pointer
	FILE * fp;
	fp=fopen("../outputs/1.txt","w");

	//Heading for output file
	fprintf(fp, "Bairstow method implementation in C language\nStep\tdR\t\tdQ\t\tp\t\tq\n");
	//intializing the array
	double a[n],b[n],c[n];
	double r,s,dR,dS;
	n--;
	i=n;
	while(i>-1){
		//Taking the initial polynomial from user
		printf("Enter a%d\n",i);
		scanf("%lf",&a[i]);
		i--;
	}
	//taking input for p and q
	printf("Please enter p\n");
	scanf("%lf",&r);
	printf("Please enter q\n");
	scanf("%lf",&s);
	dS=0;
	dR=0;
	i=1;
	j=0;
	//Entering loop
	while(i==1||(fabs(dS/s)>0.0000005)||(fabs(dR/r)>0.0000005)){
		//precision is set to 0.0000005
		r+=dR;
		s+=dS;
		//storing initial values0
		b[n]=a[n];
		c[n]=a[n];
		b[n-1]=a[n-1]+r*b[n];
		c[n-1]=b[n-1]+r*c[n];
		i=n-2;
		//Entering loop
		while(i>-1){
			b[i]=a[i]+r*b[i+1]+s*b[i+2];
			c[i]=b[i]+r*c[i+1]+s*c[i+2];
			i--;
		}
		//solving the difference of S and R
		dS = (b[0]*c[2]-b[1]*c[1])/(c[1]*c[3]-c[2]*c[2]);
		dR = (b[1]*c[2]-b[0]*c[3])/(c[1]*c[3]-c[2]*c[2]);
		//saving in the file
		
		fprintf(fp,"%d\t%lf\t%lf\t%lf\t%lf\n",j+1,dS,dR,s,r);
		j++;
	}
	//printing polynomial
	printf( "Final\np=%lf q=%lf\n\nFactorized Polynomial\n\n",r,s);
	fprintf(fp, "\nFinal\np=%lf q=%lf\n\nFactorized Polynomial\n\n",r,s);
	i=n;
	//Display Polynomial 
	while(i>-1){
		printf("%+.3lfx^%d",a[i],i);
		fprintf(fp,"%+.3lfx^%d",a[i],i);
		i--;
	}
	printf(" = (");
	fprintf(fp," = (");
	i=n;
	while(i>2){
		printf("%+.3lfx^%d",b[i],i-2);
		fprintf(fp,"%+.3lfx^%d",b[i],i-2);
		i--;
	}
	printf("%+.3lf)(",b[2]);
	printf("x^2%+.3lfx%+.3lf)\n",-1*r,-1*s);
	fprintf(fp,"%+.3lf)(",b[2]);
	fprintf(fp,"x^2%+.3lfx%+.3lf)\n",-1*r,-1*s);
	//display of result done
	//closing file pointer
	fclose(fp);
}