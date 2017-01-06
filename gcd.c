#include<stdio.h>

int main()
{
    int a,b,t;
    long long int x,y;
    scanf("%d %d",&a,&b);
    x=a,y=b;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    printf("%lld",(x*y)/a);
    //printf("%d",a);
    return 0;
}
