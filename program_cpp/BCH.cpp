#include<iostream>
#include<cstdio>
#include<queue>
#include<climits>

using namespace std;

int path[53][53]={},ans[26]={};

struct a
{
    int dist,dep,fr;
    bool operator<(const a&T) const
    {
        return dist > T.dist;
    }
}tmp;

priority_queue<a> q;

void qin(int i)
{
    int tc;
    for(tc=0;tc<52;tc++)
        {
            if(path[i][tc]!=0)
            {
                tmp.dist=path[i][tc];
                tmp.dep=tc;
                tmp.fr=i;
                q.push(tmp);
            }
        }
}

int main()
{
    int i,j=0,n,tc,te,td,m=INT_MAX;
    char ta,tb,drp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c%c %c %d",&drp,&ta,&tb,&td);
        if(ta>=65&&ta<=90) tc=ta-65;
        else if(ta>=97&&ta<=122) tc=ta-71;
        if(tb>=65&&tb<=90) te=tb-65;
        else if(tb>=97&&tb<=122) te=tb-71;
        if(path[tc][te]==0) {path[tc][te]=td; path[te][tc]=td;}
        else if(td<path[tc][te]) {path[tc][te]=td; path[te][tc]=td;}
    }
   for(i=0;i<25;i++)
   {
        int shrt[53]={};
        qin(i);
        while(not q.empty())
        {
            tmp=q.top();
            if(tmp.dep!=i)
            {
                if(shrt[tmp.dep]>tmp.dist+shrt[tmp.fr]||shrt[tmp.dep]==0) {
                    shrt[tmp.dep]=tmp.dist+shrt[tmp.fr];
                    q.pop();
                    qin(tmp.dep);
                }
                else q.pop();
            }
            else q.pop();
        }
        ans[i]=shrt[25];
    }
    for(i=0;i<25;i++) if(ans[i]<m&&ans[i]!=0) {m=ans[i]; j=i;}
    printf("%c %d",j+65,m);
    return 0;
}
