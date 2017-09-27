#include<stdio.h>
#include<time.h>

int prime[200000000]={};

int main()
{
    int i,j,lim;
    printf("Enter limit: ");
    scanf("%d",&lim);
    clock_t timeA = clock();
    for(i=2;i<=lim;i++)
    {
        if(prime[i]!=-1)
        {
            j=2;
            while(j*i<=lim)
            {
                prime[j*i]=-1;
                j++;
            }
        }
    }
    clock_t timeB = clock();

    printf("Prime list to %d:\n",lim);
    for(i=2;i<=lim;i++)
    {
        if(prime[i]!=-1)
            printf("%d ",i);
    }
    printf("\nTime use: %lf",(double)(timeB-timeA)/CLOCKS_PER_SEC);
    return 0;
}
