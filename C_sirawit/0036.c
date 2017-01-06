#include<stdio.h>

int main()
{
    long long unsigned a=1,i,in;
    scanf("%lld",&in);
    if(in%2==0)
    {
        for(i=in;i>in/2;i--) a=a*i;
        for(i=in/2;i>1;i--) a=a/i;
    }
    else
    {
        for(i=in;i>in/2+1;i--) a=a*i;
        for(i=in/2;i>1;i--) a=a/i;
        a=a*2;
    }
    printf("%lld",a);
    return 0;
}
