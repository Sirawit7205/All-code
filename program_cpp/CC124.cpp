#include<cstdio>
#include<queue>

struct a
{
    int x,y,nd;
    bool operator < (const a&T)const{
        return x > T.x;
    }
}aa;

std::priority_queue<a> q;
long long int val[100005]={};
int n,m,head[100005]={};

int findh(int nd)
{
    if(head[nd]==nd) return nd;
    else return findh(head[nd]);
}

void rem(int nd,long long int v)
{
    int x=head[nd];
    val[x]-=v;
    if(head[x]==x) return;
    else rem(x,v);
}

int main()
{
    int i,mode,a,b,t,v,x,xx;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) head[i]=i;
    for(i=1;i<=n;i++) scanf("%lld",&val[i]);
    for(i=1;i<=m;i++)
    {
        if(!q.empty())
        {
            while(q.top().x==i&&!q.empty())
            {
                aa=q.top(); q.pop();
                x=findh(aa.nd);
                val[x]+=aa.y;
            }
        }
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d",&a);
            if(head[a]==a) continue;
            else rem(a,val[a]);
            head[a]=a;
        }
        else if(mode==2)
        {
            scanf("%d %d %d %d",&a,&b,&t,&v);
            xx=findh(b);
            if(a==xx) continue;
            if(head[a]!=a) rem(a,val[a]);
            val[xx]+=val[a];
            head[a]=xx;
            aa.x=t; aa.y=v; aa.nd=a; q.push(aa);
        }
        else
        {
            scanf("%d",&a);
            x=findh(a);
            printf("%lld\n",val[x]);
        }
    }
    return 0;
}
