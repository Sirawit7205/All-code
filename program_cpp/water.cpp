#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int x,y,z;
}inp;

queue<a> qu;

int f[1001][1001]={},ans[1000005]={},ma=0;

int main()
{
    int i,n,m,q,ta,tb,sx,sy;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++) {scanf("%d %d",&ta,&tb); f[ta][tb]=-1;}
    scanf("%d %d",&sx,&sy);
    inp.x=sx; inp.y=sy; inp.z=1;
    qu.push(inp);
    while(not qu.empty())
    {
        inp=qu.front(); qu.pop();
        if(inp.x<1||inp.x>n||inp.y<1||inp.y>n||f[inp.x][inp.y]!=0) continue;
        else
        {
            if(inp.z>ma) ma=inp.z;
            ans[inp.z]++;
            f[inp.x][inp.y]=inp.z;
            sx=inp.x; sy=inp.y; ta=inp.z;
            inp.x=sx-1; inp.y=sy; inp.z=ta+1; qu.push(inp);
            inp.x=sx+1; inp.y=sy; inp.z=ta+1; qu.push(inp);
            inp.x=sx; inp.y=sy-1; inp.z=ta+1; qu.push(inp);
            inp.x=sx; inp.y=sy+1; inp.z=ta+1; qu.push(inp);
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(tb=1;tb<=n;tb++) printf("%d ",f[i][tb]);
        printf("\n");
    }*/
    for(i=1;i<=ma;i++) ans[i]+=ans[i-1];
    for(i=0;i<q;i++)
    {
        scanf("%d",&tb);
        if(tb>=ma) printf("%d\n",ans[ma]);
        else printf("%d\n",ans[tb+1]);
    }
    return 0;
}
