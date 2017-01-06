#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int x,y,f,l;
}b;

queue<a> q;

char f[105][105]={};
int rf[105][105]={},rs[105][105][4]={},x,y;

void res()
{
    int i,j;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            if(f[i][j]=='N') continue;
            else if(f[i][j]=='B') {rs[i][j][2]=1; rs[i][j][3]=1; rs[i+1][j][0]=1; rs[i][j+1][1]=1;}
            else if(f[i][j]=='R') {rs[i][j][2]=1; rs[i][j+1][1]=1;}
            else {rs[i][j][3]=1; rs[i+1][j][0]=1;}
        }
    }
}

int main()
{
    int i,j,mx,my,ml=100000,tx,ty,tl,tf;
    scanf("%d %d",&x,&y);
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++) scanf(" %c",&f[i][j]);
    }
    res();
    b.x=1; b.y=1; b.f=-1; b.l=0; q.push(b);
    while(not q.empty())
    {
        b=q.front(); q.pop();
        tx=b.x; ty=b.y; tf=b.f; tl=b.l;
        if(rf[b.x][b.y]==0||(rf[b.x][b.y]!=0&&rf[b.x][b.y]>b.l)) rf[b.x][b.y]=b.l;
        else if(rf[b.x][b.y]<=b.l) {if(b.l<ml) {ml=b.l; mx=b.x; my=b.y;} continue;}
        if(rs[tx][ty][0]==1&&tf!=0) {b.x=tx-1; b.y=ty; b.f=3; b.l=tl+1; q.push(b);}
        if(rs[tx][ty][1]==1&&tf!=1) {b.x=tx; b.y=ty-1; b.f=2; b.l=tl+1; q.push(b);}
        if(rs[tx][ty][2]==1&&tf!=2) {b.x=tx; b.y=ty+1; b.f=1; b.l=tl+1; q.push(b);}
        if(rs[tx][ty][3]==1&&tf!=3) {b.x=tx+1; b.y=ty; b.f=0; b.l=tl+1; q.push(b);}
    }
    /*for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++) printf("%d ",rf[i][j]);
        printf("\n");
    }*/
    printf("%d\n%d %d",ml+1,mx,my);
    return 0;
}
