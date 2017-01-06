#include<stdio.h>

int data[10000]={},dig[11]={};

void fact(int n)
{
    int i,t=0;
    for(i=0;i<10000;i++)
    {
        data[i]=(data[i]*n)+t;
        t=0;
        if(data[i]/10>=1)
        {
            t=data[i]/10;
            data[i]=data[i]%10;
        }
    }
}

int main()
{
    int i,n,c=0;
    scanf("%d",&n);
    data[0]=1;
    for(i=2;i<=n;i++) fact(i);
    for(i=0;i<10000;i++) if(data[i]!=0) c=i;
    for(i=0;i<=c;i++) dig[data[i]]++;
    for(i=0;i<10;i++) printf("%d=%d\n",i,dig[i]);
    for(i=c;i>=0;i--) printf("%d",data[i]);
    return 0;
}
