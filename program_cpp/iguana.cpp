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
        else return val>T.ind;
    }
}b;

priority_queue<a> q;

int main()
{
    int i,n,m,ta,tb,c[5]={},cur=0,prev;
    char mode;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&ta,&tb);
        b.ind=ta; b.val=1; q.push(b);
        b.ind=tb+1; b.val=-1; q.push(b);
    }
    b=q.top(); q.pop();
    cur+=b.val; prev=b.ind;
    while(not q.empty())
    {
        b=q.top(); q.pop();
        if(prev==b.ind) {cur+=b.val; continue;}
        else
        {
            c[cur%3]+=b.ind-prev; cur+=b.val; prev=b.ind;if(b.ind>n) break;
        }
    }
    //printf("%d %d %d",c[0],c[1],c[2]);
    scanf(" %c",&mode);
    if(mode=='R') printf("%d",(c[1]*2)+c[2]);
    else if(mode=='G') printf("%d",(c[2]*2)+c[0]);
    else printf("%d",(c[0]*2)+c[1]);
    return 0;
}
