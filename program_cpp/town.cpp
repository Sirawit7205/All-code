#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int n,m,dat[100001]={},inp[100005][4]={},v[200005]={};

queue<int> q;

void in(int a)
{
    int i,t=inp[a][2],pos=inp[a][3];
    for(i=pos;i<=pos+t-1;i++) {q.push(v[i]);}
}

int main()
{
    int i,ta,tb,Q,c=1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&inp[i][0],&inp[i][1]);
        inp[inp[i][0]][2]++; inp[inp[i][1]][2]++;
    }
    inp[1][3]=1;
    for(i=2;i<=n;i++) inp[i][3]=inp[i-1][3]+inp[i-1][2];
    for(i=1;i<=m;i++)
    {
        v[inp[inp[i][0]][3]]=inp[i][1];
        v[inp[inp[i][1]][3]]=inp[i][0];
        inp[inp[i][0]][3]++; inp[inp[i][1]][3]++;
    }
    inp[1][3]=1;
    for(i=2;i<=n;i++) inp[i][3]=inp[i-1][3]+inp[i-1][2];
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
