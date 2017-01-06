#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int n,m,k,dat[100005]={},ans[100001]={};

struct d
{
    int fr,to;
}inst;

queue<d> q;
vector<int> v[100001];

void in(int a)
{
    int i,t=v[a].size();
    for(i=0;i<t;i++) {inst.fr=a; inst.to=v[a][i]; q.push(inst);}
}

int main()
{
    int i,ta,tb,Q,c=1;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&ta,&tb);
        v[ta].push_back(tb);
        v[tb].push_back(ta);
    }
    in(m); ans[m]=0;
    while(not q.empty())
    {
        inst=q.front(); q.pop();
        if(dat[inst.to]==0&&inst.to!=m)
        {
            ans[c]=dat[inst.fr]+1; c++;
            dat[inst.to]=dat[inst.fr]+1;
            in(inst.to);
        }
    }
    scanf("%d",&Q);
    for(i=0;i<Q;i++)
    {
        scanf("%d",&ta);
        if(ans[ta-1]==0&&ta!=1) {printf("NO\n"); continue;}
        else printf("%d\n",ans[ta-1]);
    }
    //for(i=0;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}
