#include<stdio.h>

int main()
{
    int i,n;
    long long int a,b,t,x,y,dat[100005]={};
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%lld",&dat[i]);
    a=dat[0];
    for(i=1;i<n;i++)
    {
        b=dat[i];
        x=a; y=b;
        while(b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }
        a=(x*y)/a;
    }
    printf("%lld",a);
    return 0;
}

