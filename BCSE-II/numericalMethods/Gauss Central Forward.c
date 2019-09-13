//Implementation of Gauss Central in C language
//Including system library
#include<stdio.h>
#include<math.h>
//Defining constants to maintain integrity
#define Max 10

//function to display the array
void dispArr(float arr[Max*2][Max*2],int n) {
    int i,j;
    //nested loop
    while(i<n) {
        printf("\n");
        j=0;
        while(j<n) {
            printf("%f",arr[i][j]);
            j++;
        }
        i++;
    }
}

//function to print array in file
void printArr(float arr[Max*2][Max*2],int n,FILE * fp) {
    int i,j;
    //nested loop
    while(i<n) {
        fprintf(fp,"\n");
        j=0;
        while(j<n) {
            fprintf(fp,"%f",arr[i][j]);
            j++;
        }
        i++;
    }
}

//main function
int main()
{
    //variables defination
    int n;                          // number of pairs.
    int i,j;                        // Loop variables
    float ax[Max];                  // 'X' array limit 9
    float ay[Max];                  // 'Y' array limit 9
    float x,h,p,nr,dr;              // user input from x
    float y=0;                      // Calculated value for coressponding X.
    float difference[Max*2][Max*2]; // to store Y
    float y1,y2,y3,y4;              // temp variables

    // Taking number of inputs
    printf("\nPlease enter the number of (x,y) pairs\t");
    scanf("%d",&n);

    // Input Sequel for array X
    printf("\n\nEnter the value of x and y\t");
    // Input loop for X.
    for(i=0; i<n; i++)
    {
        printf("\nEnter the value of x%d\t",i+1);
        scanf("%f",&ax[i]);
        printf("\nEnter the value of y%d\t",i+1);
        scanf("%f",&ay[i]);
    }

    // Inputing the required value quarry
    printf("\n\nEnter the value of x for f(x)\t");
    scanf("%f",&x);

    // Calculation and processing section.
    h=ax[1]-ax[0];
    //for loop
    for(i=0; i<n-1; i++){
        difference[i][1]=ay[i+1]-ay[i];
    }
    //nested loop
    for(j=2; j<=4; j++){
        for(i=0; i<n-j; i++){
            difference[i][j]=difference[i+1][j-1]-difference[i][j-1];
        }
    }
    i=0;
    //finding the position of value below x
    do
    {
        i++;
    }
    while(ax[i]<x);

    i--;
    //calculation of p and subsequents Y[]
    p=(x-ax[i])/h;
    y1=p*difference[i][1];
    y2=p*(p-1)*difference[i-1][2]/2;
    y3=(p+1)*p*(p-1)*difference[i-2][3]/6;
    y4=(p+1)*p*(p-1)*(p-2)*difference[i-3][4]/24;

    // Taking sum
    y=ay[i]+y1+y2+y3+y4;

    // Output Section
    //intialize file pointer
    FILE *fp = fopen("../outputs/6.txt","w");
    i   =   0;
    int z = n;
    //printing in output file
    fprintf(fp,"Gauss Central method implementation in C language\n\nx\t\ty\t\t");
    for(i=1;i<n;i++) fprintf(fp, "Y%d\t\t", i);
    fprintf(fp,"\n");
    i=0;
    //printing the table in output file
    while(i<n)
    {
        fprintf(fp,"%f\t%f",ax[i],ay[i]);
        j   =   1;
        while(j<z){
            fprintf(fp,"\t%f",difference[i][j]);
            j++;
        }
    fprintf(fp,"\n");
    z--;
    i++;
    }
    //printing results in a application and output
    printf("\nAt x = %6.4f , f(x) = %6.8f\n",x,y);
    fprintf(fp,"\nAt x = %6.4f , f(x) = %6.8f\n",x,y);
    //closing file pointer
    fclose(fp);
}