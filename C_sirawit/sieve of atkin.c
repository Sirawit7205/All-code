#include<stdio.h>
#include<math.h>
#include<time.h>

int prime[200000000]={};

int main()
{
    int lim,i,j,n,max;

    printf("Enter limit: ");
    scanf("%d",&lim);
    printf("Prime list to %d:\n",lim);
    clock_t timeA = clock();

    prime[2]=1;                 //known primes
    prime[3]=1;

    max=sqrt(lim);              //half way

    for(i=1;i<=max;i++)         //opt 1: all
    {
        for(j=1;j<=max;j+=2)    //opt 1: odd only
        {
            n=(4*i*i)+(j*j);                //rule 1: n=4x^2+y^2
            if(n<=lim&&(n%12==1||n%12==5))  //mod 12 equals to 1 or 5 (simplify mod 60)
                prime[n]++;
        }
    }

    for(i=1;i<=max;i+=2)        //opt 2: odd only
    {
        for(j=2;j<=max;j+=2)    //opt 2: even only
        {
            n=(3*i*i)+(j*j);                //rule 2: n=3x^2+y^2
            if(n<=lim&&n%12==7)             //mod 12 equals to 7 (simplify mod 60)
                prime[n]++;
        }
    }

    for(i=2;i<=max;i++)         //opt 3: all from 2
    {
        for(j=1;j<=max;j++)     //opt 3: all
        {
            n=(3*i*i)-(j*j);                //rule 3: n=3x^2-y^2 when x>y
            if(n<=lim&&i>j&&n%12==11)       //mod 12 equals to 11 (simplify mod 60)
                prime[n]++;
        }
    }

    for(i=5;i<max;i++)                      //sieving multiples of
    {
        if(prime[i]%2==1)                   //prime numbers' perfect squares
        {
            for(j=i*i;j<=lim;j+=i*i)
                prime[j]=0;
        }
    }
    clock_t timeB = clock();

    for(i=1;i<=lim;i++)                     //printing results
    {
        if(prime[i]%2==1)
            printf("%d ",i);
    }
    printf("\nTime use: %lf",(double)(timeB-timeA)/CLOCKS_PER_SEC);
    return 0;
}
