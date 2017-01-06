#include<iostream>
#include<cstdio>

#define INF 2000000000

using namespace std;

int p[500005]={},k,c[500005][2]={};

int chk(int n)
{
    int i,t;
    if(n<=0) return INF;
    if(n==1) return p[1];
    if(c[n][1]==1) return c[n][0];
    else
    {
        c[n][1]=1;
        for(i=1;i<k;i++)
        {
            //if(n-i<1||n-i-1<1) {return c[n][0]=p[1];}
            {t=min(chk(n-i)+p[n-i],chk(n-i-1)+p[n-i-1]); if(c[n][0]==0||c[n][0]>t) c[n][0]=t; return t;}
        }
    }
}

int main()
{
    int i,n,x;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=1;i<=n;i++) scanf("%d",&p[i]);
    x=chk(n);
    printf("%d",x);
    return 0;
}
