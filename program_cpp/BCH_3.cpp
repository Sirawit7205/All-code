#include<iostream>
#include<cstdio>
#include<queue>
#include<climits>

using namespace std;

struct data
{
    int node,dist;
    data(int a,int b)
    {
        node=a;
        dist=b;
    }
    bool operator < (const data &T) const
    {
        return dist > T.dist;
    }
};

priority_queue<data> q;
int f[500][500]={},ans[500]={};

void chk()
{
    int a=q.top().node,b=q.top().dist,i;
    if(q.empty()) return;
    if(ans[a]==-1)
    {
        for(i=65;i<90;i++) if(f[a][i]!=0) q.push(data(i,f[a][i]+b));
        for(i=97;i<=122;i++) if(f[a][i]!=0) q.push(data(i,f[a][i]+b));
        ans[a]=b;
    }
    q.pop();
    chk();
}

int main()
{
    int p,i,tc,m=INT_MAX,a=0;
    char ta,tb;
    scanf("%d",&p);
    for(i=0;i<200;i++) ans[i]=-1;
    for(i=0;i<p;i++)
    {
        scanf(" %c %c %d",&ta,&tb,&tc);
        if(f[ta][tb]==0||(f[ta][tb]!=0&&tc<f[ta][tb])) {f[ta][tb]=tc; f[tb][ta]=tc;}
    }
    q.push(data(90,0));
    chk();
    for(i=65;i<90;i++) if(ans[i]!=-1&&ans[i]<m) {m=ans[i]; a=i;}
    printf("%c %d",a,m);
    return 0;
}
