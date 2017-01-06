#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int x,y,z;
}inp;

queue<a> q;
int ans[27]={},ma=5000,rt[55][55]={};
char f[55][55]={};

int main()
{
    int i,j,m,n,sx,sy,ta,tb;
    char t,d;
    scanf("%d %d %d %d",&m,&n,&sx,&sy);
    for(i=0;i<n;i++)
    {
        scanf("%c",&d);
        for(j=0;j<m;j++)
        {
            scanf("%c",&t);
            if(t=='1') f[i][j]='a';
            else f[i][j]=t;
        }
    }
    inp.y=sx; inp.x=sy; inp.z=1;
    q.push(inp);
    while(not q.empty())
    {
        inp=q.front(); q.pop();
        if(inp.x<0||inp.y<0||inp.x>n-1||inp.y>m-1||f[inp.x][inp.y]=='a') continue;
        else if(f[inp.x][inp.y]>=65&&f[inp.x][inp.y]<=90) ans[f[inp.x][inp.y]-65]=inp.z;
        else if(f[inp.x][inp.y]=='0')
        {
            rt[inp.x][inp.y]=inp.z;
            f[inp.x][inp.y]='1';
            ta=inp.y; tb=inp.x; inp.z++;
            inp.y=ta-1; inp.x=tb; q.push(inp);
            inp.y=ta+1; inp.x=tb; q.push(inp);
            inp.y=ta; inp.x=tb-1; q.push(inp);
            inp.y=ta; inp.x=tb+1; q.push(inp);
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) printf("%d ",rt[i][j]);
        printf("\n");
    }*/
    for(i=0;i<26;i++) if(ans[i]!=0&&ans[i]<ma) ma=ans[i];
    for(i=0;i<26;i++) if(ans[i]==ma) printf("%c\n",i+65);
    return 0;
}
