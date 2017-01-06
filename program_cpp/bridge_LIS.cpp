#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int ma[3005]={},x[3005]={};

struct d
{
    int n,s;
}dat[3005];

int cmp(d a,d b)
{
    return a.s<b.s;
}

int main()
{
    int i,j,n,m,sa=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&dat[i].n);
    for(i=0;i<n;i++) scanf("%d",&dat[i].s);
    //sort(dat,dat+n,cmp);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dat[j].n==dat[i-1].s) x[i]=j+1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(sa==0) {m=sa; sa++;}
        else if(ma[sa-1]==x[i]) continue;
        else if(ma[sa-1]<x[i]) {m=sa; sa++;}
        else
        {
            m=upper_bound(ma,ma+sa,x[i])-ma;
        }
        if(ma[m-1]==x[i]) continue;
        ma[m]=x[i];
    }
    printf("%d",sa);
    return 0;
}
