#include<stdio.h>

int price[4]={500,800,1500,3000},no[4]={1,2,5,15};
long n,ans=0;

int chk(long n,int p,int t)
{
    if(n==0) return;
    if(n>=no[t])
    {
    ans+=price[p]; n-=no[t];
    if(n>=no[t])
        chk(n,p,t);
    else
        chk(n,p-1,t-1);
    }
    else
    chk(n,p-1,t-1);
}

int main()
{
    scanf("%d",&n);
    chk(n,3,3);
    printf("%ld",ans);
    return 0;
}
