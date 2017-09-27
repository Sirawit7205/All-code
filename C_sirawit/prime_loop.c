#include<stdio.h>
#include<time.h>

int main()
{
    int lim,i,j,mark;
    printf("Enter limit: ");
    scanf("%d",&lim);
    printf("Prime list to %d:\n",lim);
    clock_t timeA = clock();
    for(i=2;i<=lim;i++)
    {
        mark=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                mark=1;
                break;
            }
        }
        if(mark==0)
            printf("%d ",i);
    }
    clock_t timeB = clock();
    printf("\nTime use: %lf",(double)(timeB-timeA)/CLOCKS_PER_SEC);
    return 0;
}
