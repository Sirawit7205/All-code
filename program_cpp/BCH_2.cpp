#include<iostream>
#include<cstdio>
#include<queue>
#include<climits>

using namespace std;

int path[53][53]={},shrt[60]={};

struct a
{
    int dist,node;
    bool operator<(const a&T) const
    {
        return dist > T.dist;
    }
}tmp;

priority_queue<a> q;

/*void qin(int i)
{
    int tc;
    for(tc=0;tc<52;tc++)
        {
            if(path[i][tc]!=0)
            {
                tmp.dist=path[i][tc]+shrt[i];
                tmp.dep=tc;
                tmp.fr=i;
                q.push(tmp);
            }
        }
}*/

int main()
{
    int i,j=0,n,tc,te,td,m=INT_MAX,x;
    char ta,tb;
    scanf("%d",&n);
    for(i=0;i<55;i++) shrt[i]=-1;
    for(i=0;i<n;i++)
    {
        scanf(" %c %c %d",&ta,&tb,&td);
        if(ta>=65&&ta<=90) tc=ta-65;
        else if(ta>=97&&ta<=122) tc=ta-71;
        if(tb>=65&&tb<=90) te=tb-65;
        else if(tb>=97&&tb<=122) te=tb-71;
        if(path[tc][te]==0||(path[tc][te]!=0&&path[tc][te]>td)) {path[tc][te]=td; path[te][tc]=td;}
    }
    tmp.dist=0; tmp.node=25; q.push(tmp);
    while(not q.empty())
    {
        tmp=q.top(); q.pop();
        td=tmp.node; x=tmp.dist;
        if(shrt[td]==-1)
        {
            for(tc=0;tc<52;tc++)
            {
                if(tc==25) continue;
                if(path[td][tc]!=0) {tmp.dist=path[td][tc]+x; tmp.node=tc; q.push(tmp);}
            }
            shrt[td]=x;
        }

    }
    //for(i=0;i<52;i++) printf("%d %d\n",i,shrt[i]);
    for(i=0;i<25;i++) if(shrt[i]<m&&shrt[i]!=-1) {m=shrt[i]; j=i;}
    printf("%c %d",j+65,m);
    return 0;
}

