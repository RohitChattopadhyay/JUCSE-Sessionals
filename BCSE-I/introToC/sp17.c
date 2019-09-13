#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct st
{
    char number[20];
    int subject1;
    int subject2;
    int Avg;
};
void arraysort(struct st *array, int number)
{
   int Avgflag1, Avgflag2;
   struct st Avgflag3;
   for (Avgflag1 = 1; Avgflag1 < number; Avgflag1++)
   {
       Avgflag3.Avg = array[Avgflag1].Avg;
       strcpy(Avgflag3.number,array[Avgflag1].number);
       Avgflag3.subject1=array[Avgflag1].subject1;
       Avgflag3.subject2=array[Avgflag1].subject2;
       Avgflag2 = Avgflag1-1;
       while (Avgflag2 >= 0 && array[Avgflag2].Avg > Avgflag3.Avg)
       {
           strcpy(array[Avgflag2+1].number,array[Avgflag2].number);
           array[Avgflag2+1].subject1=array[Avgflag2].subject1;
           array[Avgflag2+1].subject2=array[Avgflag2].subject2;
           array[Avgflag2+1].Avg=array[Avgflag2].Avg;
           Avgflag2 = Avgflag2-1;
       }
       array[Avgflag2+1].Avg= Avgflag3.Avg;
       strcpy(array[Avgflag2+1].number,Avgflag3.number);
       array[Avgflag2+1].subject1=Avgflag3.subject1;
       array[Avgflag2+1].subject2=Avgflag3.subject2;
   }
}
void main()
{
    struct st *f;
    char name[20];
    int s1=0, s2=0;
    int Avgflag1=0, t=0, Avgflag2=0;
    FILE *f1;
    FILE *f2;
    f1=fopen("text.txt","r");
    f2=fopen("text2.txt","w");
    if(f1==NULL)
    {
        printf("\nError while reading\n");
        exit(0);
    }
     if (f2 == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("Read data:\n");
    f=(struct st*)malloc(1*sizeof(struct st));
    fscanf(f1,"%s",name);
    fscanf(f1,"%d", &s1);
    fscanf(f1,"%d", &s2);
    while(!feof(f1))
    {
        strcpy(f[Avgflag2].number,name);
        f[Avgflag2].subject1=s1;
        f[Avgflag2].subject2=s2;
        f[Avgflag2].Avg=((s1+s2)/2);
        printf("%s %d %d %d\n", f[Avgflag2].number, f[Avgflag2].subject1, f[Avgflag2].subject2, f[Avgflag2].Avg);
        Avgflag2++;
        f=(struct st*)realloc(f, (Avgflag2+1)*sizeof(struct st));
        fscanf(f1,"%s",name);
        fscanf(f1,"%d", &s1);
        fscanf(f1,"%d", &s2);
    }
    arraysort(f, Avgflag2);
    printf("Sorted data\n");
    for(Avgflag1=0;Avgflag1<Avgflag2;Avgflag1++)
    {
        printf("%s %d %d %d\n",f[Avgflag1].number, f[Avgflag1].subject1, f[Avgflag1].subject2 ,f[Avgflag1].Avg);
        fprintf(f2,"%s %d %d %d\n",f[Avgflag1].number, f[Avgflag1].subject1, f[Avgflag1].subject2 ,f[Avgflag1].Avg);
    }
    fclose(f1);
    fclose(f2);
}
