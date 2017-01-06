#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int n,m,dat[100001]={};

queue<int> q;
queue<int> v[100001];
void in(int a)
{
    int i,x,t=v[a].size();
    for(i=0;i<t;i++)
        {
            x=v[a].front();
            q.push(x);
            v[a].push(x);
            v[a].pop();
        }
}

int main()
{
    int i,ta,tb,Q,c=1;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&ta,&tb);
        v[ta].push(tb);
        v[tb].push(ta);
    }
    for(i=1;i<=n;i++)
    {
        if(dat[i]==0)
        {
            in(i); dat[i]=c;
            while(not q.empty())
            {
                ta=q.front(); q.pop();
                if(dat[ta]==0)
                {
                    dat[ta]=c;
                    in(ta);
                }
            }
            c++;
        }
    }
    scanf("%d",&Q);
    for(i=0;i<Q;i++)
    {
        scanf("%d %d",&ta,&tb);
        if(dat[ta]==dat[tb]) printf("YES\n");
        else printf("NO\n");
    }
    //for(i=1;i<=n;i++) printf("%d ",dat[i]);
    return 0;
}
