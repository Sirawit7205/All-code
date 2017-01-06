#include<stdio.h>

int main()
{
    long long int a,b,t,i;
    scanf("%lld %lld",&a,&b);
    if(b>a) {t=a; a=b; b=t;}
    for(i=a;i>=1;i--)
    {
        if(a%i==0&&b%i==0) {break;}
    }
    printf("%lld",a*(b/i));
    return 0;
}

