#include<stdio.h>

long price=0;

int main()
{
    int n,t;
    scanf("%d",&n);
    if(n>=15)
    {
        price+=(n/15)*3000;
        n=n%15;
    }
    if(n==0) printf("%ld",price);
    else
    {
        if(n>=9&&n<=14) price+=3000;
        else if(n==8) price+=2800;
        else if(n==7) price+=2500;
        else if(n==6) price+=2000;
        else if(n==4||n==5) price+=1500;
        else if(n==3) price+=1300;
        else if(n==2) price+=800;
        else price+=500;

    }
    printf("%ld",price);
    return 0;
}
