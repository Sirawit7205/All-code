#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct a
{
    int p,h;
    bool operator < (const a&T) const
    {
        if(h!=T.h) return h<T.h;
        else return p<T.p;
    }
}b;

int amt[200005]={};
a stk[1000005]={};

int main()
{
    int i,m,n,k,t,cur,ma=0,use=0;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&amt[i]);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d",&stk[i].p,&stk[i].h);
    }
    sort(stk+1,stk+k+1);
    //for(i=1;i<=k;i++) printf("%d %d\n",stk[i].p,stk[i].h);
    for(i=k;i>0;i--) {t=amt[stk[i].p]; amt[stk[i].p]=amt[stk[i].p+1]; amt[stk[i].p+1]=t;}
    //for(i=1;i<=n;i++) printf("%d ",amt[i]);
    scanf("%d",&cur);
    ma=amt[cur];
    for(i=1;i<=k;i++)
    {
        if(stk[i].h==stk[i-1].h&&stk[i].p==cur&&stk[i-1].p==cur-2) t=max(amt[cur-2],amt[cur+1]); else t=max(amt[cur-1],amt[cur+1]);
        if(t>ma) {ma=t; use=1;}
        t=amt[stk[i].p]; amt[stk[i].p]=amt[stk[i].p+1]; amt[stk[i].p+1]=t;
        if(stk[i].p==cur) cur++;
        else if(stk[i].p+1==cur) cur--;
    }
    t=max(amt[cur-1],amt[cur+1]);
    if(t>ma) {ma=t; use=1;}
    printf("%d\n",ma);
    if(use==0) printf("NO"); else printf("USE");
    return 0;
}
