#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int i,v;
    bool operator<(const a&T) const
    {
        if(v!=T.v) return v>T.v;
        else return i>T.i;
    }
}inp;

priority_queue<a> q;

int p[500005]={};

int main()
{
    int i,n,k,c,t;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=1;i<=n;i++) scanf("%d",&p[i]);
    c=1; for(i=c+1;i<=c+k;i++) {inp.i=i; inp.v=p[i]+p[1]; q.push(inp);}
    while(1)
    {
        inp=q.top(); q.pop();
        if(inp.i+k>=n) {printf("%d",inp.v+p[n]); return 0;}
        else
        {
            c=inp.i; t=inp.v;
            for(i=c+1;i<=c+k;i++)
                {inp.i=i; inp.v=p[i]+t; q.push(inp);}
        }
    }
    return 0;
}
