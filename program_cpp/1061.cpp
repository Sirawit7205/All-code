#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int x,y,cur;
}b;

queue<a> q;
int dat[25][25]={};

int main()
{
    int m,x,y,i,j,ma,ta,tb,tc;
    scanf("%d",&m);
    scanf("%d %d",&y,&x);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++) scanf("%d",&dat[i][j]);
    }
    ma=dat[x][y];
    b.x=x; b.y=y; b.cur=dat[x][y]; q.push(b); dat[x][y]=-9;
    while(not q.empty())
    {
        b=q.front(); q.pop();
        ta=b.x; tb=b.y; tc=b.cur;
        if(ta-1>0&&dat[ta-1][tb]>tc&&dat[ta-1][tb]!=100) {if(dat[ta-1][tb]>ma) ma=dat[ta-1][tb]; b.x=ta-1; b.y=tb; b.cur=dat[ta-1][tb]; q.push(b); dat[ta-1][tb]=-9;}
        if(ta+1<=m&&dat[ta+1][tb]>tc&&dat[ta+1][tb]!=100) {if(dat[ta+1][tb]>ma) ma=dat[ta+1][tb]; b.x=ta+1; b.y=tb; b.cur=dat[ta+1][tb]; q.push(b); dat[ta+1][tb]=-9;}
        if(tb-1>0&&dat[ta][tb-1]>tc&&dat[ta][tb-1]!=100) {if(dat[ta][tb-1]>ma) ma=dat[ta][tb-1]; b.x=ta; b.y=tb-1; b.cur=dat[ta][tb-1]; q.push(b); dat[ta][tb-1]=-9; }
        if(tb+1<=m&&dat[ta][tb+1]>tc&&dat[ta][tb+1]!=100) {if(dat[ta][tb+1]>ma) ma=dat[ta][tb+1]; b.x=ta; b.y=tb+1; b.cur=dat[ta][tb+1]; q.push(b); dat[ta][tb+1]=-9; }
    }
    printf("%d",ma);
    return 0;
}
