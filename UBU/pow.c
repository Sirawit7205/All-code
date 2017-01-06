#include<stdio.h>

int main()
{
    long long int a,b,c,i,d=1;
    scanf("%lld %lld %lld",&a,&b,&c);
    for(i=0;i<b;i++) d*=a;
    printf("%lld",d%c);
    return 0;
}
