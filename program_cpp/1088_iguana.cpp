#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int ind,val;
    bool operator < (const a&T) const
    {
        if(ind!=T.ind) return ind > T.ind;
        else return val>T.val;
    }
} b;

priority_queue<a> q;

int main()
{
    int i,n,m,ta,tb;
    long long int c[5]= {},cur=0,prev,reach=0;
    char mode;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&ta,&tb);
        b.ind=ta;
        b.val=1;
        q.push(b);
        if(tb+1<=n)
        {
            b.ind=tb+1;
            b.val=-1;
            q.push(b);
        }
    }
    cur=0;
    prev=1;
    b.ind=n+1;
    b.val=0;
    q.push(b);
    //while(not q.empty()) {printf("%d %d\n",q.top().ind,q.top().val); q.pop();}
    while(not q.empty())
    {
        b=q.top();
        q.pop();
        if(prev==b.ind)
        {
            cur+=b.val;
            if(not q.empty()) continue;
        }
        if(prev!=b.ind)
        {
            c[cur%3]+=b.ind-prev;
            reach+=b.ind-prev;
            cur+=b.val;
            prev=b.ind;
        }
        else
        {
            c[cur%3]+=prev-reach;
        }
    }
    //c[cur%3]+=n-prev;
    //printf("%d %d %d",c[0],c[1],c[2]);
    scanf(" %c",&mode);
    if(mode=='R') printf("%lld",(c[1]*2)+c[2]);
    else if(mode=='G') printf("%lld",(c[2]*2)+c[0]);
    else printf("%lld",(c[0]*2)+c[1]);
    return 0;
}
