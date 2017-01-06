#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int chk[1005][1005]={},da,db;

struct a{
    int x,y,t;
    a(int xx,int yy,int tt) {x=xx; y=yy; t=tt;}
}

;queue<a> q;

int main()
{
    int n,i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) {scanf("%d",&chk[i][j]); if(chk[i][j]==0) {da=i; db=j;}}
    }
    q.push(a(da,db,0))
    while(!q.empty())
    {
        tx=q.front().x; ty=q.front().y; tc=q.front().t; q.pop();
        chk[x][y]=true; ans++;
        if(tc!=tm) {if(ans-1>=c) {printf("%lld",tm); break;} else tm++;}
        if(chk[tx-1][ty]==false&&tx-1>0) q.push(a(tx-1,ty,tc+1));
        if(chk[tx+1][ty]==false&&tx+1<=n) q.push(a(tx+1,ty,tc+1));
        if(chk[tx][ty-1]==false&&ty-1>0) q.push(a(tx,ty-1,tc+1));
        if(chk[tx][ty+1]==false&&ty+1<=n) q.push(a(tx,ty+1,tc+1));
    }
    return 0;
}

