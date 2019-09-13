//Implementation of Newton Forward Differentiation in C language
//Including libraries
#include<stdio.h>
#include <math.h>

//declaring functions
//Computing f(x,y)
double fxy(double x,double y){
    return x-sin(x+y);
}
//Computing g(x,y)
double gxy(double x,double y){
    return y-cos(x-y);
}
//Computing df/dx
double fdx(double x,double y){
    return 1-cos(x+y);
}
//Computing df/dy
double fdy(double x,double y){
    return ((-1)*cos(x+y));
}
//Computing dg/dx
double gdx(double x,double y){
    return sin(x-y);
}
//Computing dg/dy
double gdy(double x,double y){
    return 1-sin(x-y);
}

int main()
{
    FILE *fp;//Opening file pointer
    fp=fopen("../outputs/20.txt","w");//Create a new file to write output data into
    float x1,x2,y1,y2,diff1,diff2;
    printf("Implementation of Newton Ralpshon Multivariable method in C language\n\n");
    printf("Initial Approx. of x: ");
    scanf("%f",&x1);//Accept initial approximation for x
    printf("Initial Approx. of y: ");
    scanf("%f",&y1);//Accept initial approximation for y
    
    int count=1;//To keep a count of steps
    fprintf(fp,"Implementation of Newton Ralpshon Multivariable method in C language\n\nStep\tx\t\ty\t\tx'\t\ty'\t\tf(x,y)\t\tg(x,y)\t\tError(x)\tError(y)\n\n");//Write table heading
    do
    {
        //Compute del(x)
        diff1=gxy(x1,y1)*fdy(x1,y1)-fxy(x1,y1)*gdy(x1,y1);
        diff1/=(fdx(x1,y1)*gdy(x1,y1)-fdy(x1,y1)*gdx(x1,y1));
        
        //Compute del(y)
        diff2=fxy(x1,y1)*gdx(x1,y1)-gxy(x1,y1)*fdx(x1,y1);
        diff2/=(fdx(x1,y1)*gdy(x1,y1)-fdy(x1,y1)*gdx(x1,y1));
        
        //Update value of x to a closer approx.
        x2=x1+diff1;
        
        //Update value of y to a closer approx.
        y2=y1+diff2;
        
        //Write the data into the file for each file
        fprintf(fp," %d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t\n",count,x1,y1,x2,y2,fxy(x1,y1),gxy(x1,y1),diff1,diff2);
        
        x1=x2;//Assign xi+1 as xi for the next iteration
        y1=y2;//Assign yi+1 as yi for the next iteration
        count++;//Increment the count of steps
 
    }while(fmax(fabs(diff1),fabs(diff2))>0.000001);//To calculate the roots of the non linear equation correct upto 6th decimal place
    
    fprintf(fp,"\n\nResult\n  x = %f , y = %f\n",x2,y2);//Write the obtained data into the output file
    printf("\n\nResult\n  x = %f , y = %f\n",x2,y2);//Write the obtained data in terminal
    fclose(fp);//Close the file pointer
    return 0;
}
