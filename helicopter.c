#include<stdio.h>

int gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int m,n,a;
    scanf("%d %d",&n,&m);
    m--; n--;
    if(m==0||n==0) a=0;
    else if(m==1) a=n;
    else if(n==1) a=m;
    else if(m==n) a=m;
    else if(m>n)
    {
        if(m%n==0) a=m;
        else a=m+(n-gcd(n,m));
    }
    else
    {
        if(n%m==0) a=n;
        else a=n+(m-gcd(m,n));
    }
    printf("%d",a);
    return 0;
}
