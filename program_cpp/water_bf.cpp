#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

bool chk[10005][10005]={};

struct a{
    int x,y,t;
    a(int xx,int yy,int tt) {x=xx; y=yy; t=tt;}
}

;queue<a> q;

int main()
{
    int n,x,y,tx,ty;
    long long int c,ans=0,tc,tm=0;
    scanf("%d %d %d %lld",&n,&x,&y,&c);
    q.push(a(x,y,0));
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
