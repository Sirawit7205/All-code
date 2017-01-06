#include<cstdio>
#include<algorithm>

struct a
{
    int x,y,l;
    bool operator < (const a&T)const{
        return l < T.l;
    }
}aa;

long long int ans=0;
int head[100005]={},n,m,str[100005]={};
a q[1000005]={};

int findh(int a)
{
    if(head[a]==a) return a;
    else return head[a]=findh(head[a]);
}

int main()
{
    int i,x,y,ta,tb,in=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {scanf("%d",&str[i]); head[i]=i;}
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&ta,&tb);
        aa.x=ta; aa.y=tb; aa.l=str[ta]+str[tb]; q[i]=aa;
    }
    std::sort(q,q+m);
    for(i=0;i<m;i++)
    {
        x=findh(q[i].x); y=findh(q[i].y);
        if(x==y) continue;
        else
        {
            ans+=q[i].l;
            in++;
            head[x]=y;
        }
        if(in==n) break;
    }
    printf("%lld",ans);
    return 0;
}
