#include<stdio.h>

int main()
{
    int i,n,a,b,t,dat[100005]={};
    long long int c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&dat[i]);
    a=dat[0];
    for(i=1;i<n;i++)
    {
        b=dat[i];
        while(b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }
    }
    for(i=0;i<n;i++) c+=dat[i]/a;
    printf("%lld",c);
    return 0;
}
