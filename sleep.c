#include<stdio.h>
#include<string.h>

int dat[1000002][2]={};

int rec(int n)
{
    int i,c=1,ta,tb,slp=0;
    memset(dat,0,sizeof(dat));
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&ta,&tb);
        dat[ta][0]++; dat[tb][1]++;
        c+=2;
    }
    for(i=1;i<=1000000;i++)
    {
        if(dat[i][0]!=0)
        {
            slp+=dat[i][0];
            if(slp==n) return 1;
        }
        if(dat[i][1]!=0)
        {
            slp-=dat[i][1];
        }
    }
    return 0;
}

int main()
{
    int i,n,t,c;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        c=rec(n);
        if(c==0) printf("yes\n"); else printf("no\n");
    }
    return 0;
}
