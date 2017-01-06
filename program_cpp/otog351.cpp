#include<cstdio>
#include<cmath>

int cnt[50]={},prime[30000]={},pcnt[250000]={},pa=2,mx=5,t;

int chk(int m)
{
    int x,y;
    if(m<=0) return 0;
    else if(cnt[m]!=0) return cnt[m];
    else
    {
        if(cnt[m-1]!=0) x=cnt[m-1]; else x=chk(m-1);
        if(cnt[m-4]!=0) y=cnt[m-4]; else y=chk(m-4);
        return cnt[m]=x+y;
    }
}

void fp(int m)
{
    int i,c;
    if(m%2==0) m++;
    while(mx<=m)
    {
        t=sqrt(mx); c=0;
        for(i=1;i<=pa;i++)
        {
            if(prime[i]>t) break;
            if(mx%prime[i]==0) {pcnt[mx]=pa; pcnt[mx+1]=pa; c=1; break;}
        }
        if(c==0) {pa++; prime[pa]=mx; pcnt[mx]=pa; pcnt[mx+1]=pa;}
        mx+=2;
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    cnt[1]=1; cnt[2]=1; cnt[3]=1; cnt[4]=2;
    prime[1]=2; prime[2]=3; pcnt[2]=1; pcnt[3]=2; pcnt[4]=2;
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        m=chk(m);
        if(m<2) printf("0\n");
        else if(pcnt[m]!=0) printf("%d\n",pcnt[m]);
        else {fp(m); printf("%d\n",pcnt[m]);}
    }
    return 0;
}
