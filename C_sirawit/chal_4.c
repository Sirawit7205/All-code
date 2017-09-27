#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_DRAW 100
#define MAX_PHOTO 90
#define COMP 3
#define SAMPLE 1000000

int main()
{
    int i,j,k,A,B,C,draw,a[MAX_DRAW]={};
    double count=0;

    printf("Amount to buy: ");
    scanf("%d",&draw);

    srand(time(NULL));

    for(k=0;k<SAMPLE;k++)
    {
        for(i=0;i<draw;i++)
        {
            a[i]=rand()%MAX_PHOTO;
        }

        for(i=0;i<MAX_PHOTO;i+=COMP)
        {
            A=0;
            B=0;
            C=0;
            for(j=0;j<draw;j++)
            {
                if(a[j]==i)
                    A=1;
                if(a[j]==i+1)
                    B=1;
                if(a[j]==i+2)
                    C=1;
            }
            if(A&&B&&C)
            {
                count++;
                break;
            }
        }
    }
    printf("Probability = %lf",count/SAMPLE);
    return 0;
}
