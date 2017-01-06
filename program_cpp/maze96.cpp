#include<iostream>
#include<cstdio>
#include<queue>
#include<climits>

using namespace std;

struct din
{
	int x,y,d;
}a;

queue<din> q;
int dat[155][155]={}, dest[155][155]={},c=0,m=INT_MAX; 

void testexp(int x, int y,int cn)
{
	if(dest[x-1][y]>0&&x-1>0) {if(dest[x][y]!=-1) {c++; dest[x][y]=-1;} if(cn+dest[x-1][y]+1<m) m=cn+dest[x-1][y]+1;}
	if(dest[x][y-1]>0&&y-1>0) {if(dest[x][y]!=-1) {c++; dest[x][y]=-1;}  if(cn+dest[x][y-1]+1<m) m=cn+dest[x][y-1]+1;}
	if(dest[x][y+1]>0) {if(dest[x][y]!=-1) {c++; dest[x][y]=-1;}  if(cn+dest[x][y+1]+1<m) m=cn+dest[x][y+1]+1;}
	if(dest[x+1][y]>0) {if(dest[x][y]!=-1) {c++; dest[x][y]=-1;}  if(cn+dest[x+1][y]+1<m) m=cn+dest[x+1][y]+1;}
}

int main()
{
	int x,y,fx,fy,dx,dy,i,j,ta,tb,tc;
	scanf("%d %d",&x,&y);
	scanf("%d %d",&fx,&fy);
	scanf("%d %d",&dx,&dy);
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++) scanf("%d",&dat[i][j]);
	}
	a.x=dx; a.y=dy; a.d=1; q.push(a);
	dat[dx][dy]=-1;
	while(not q.empty())
	{
		a=q.front(); q.pop();
		ta=a.x; tb=a.y; tc=a.d;
		dest[ta][tb]=tc;
		if(dat[ta-1][tb]==1) {dat[ta-1][tb]=-1; a.x=ta-1; a.y=tb; a.d=tc+1; q.push(a);}
		if(dat[ta][tb-1]==1) {dat[ta][tb-1]=-1; a.x=ta; a.y=tb-1; a.d=tc+1; q.push(a);}
		if(dat[ta][tb+1]==1) {dat[ta][tb+1]=-1; a.x=ta; a.y=tb+1; a.d=tc+1; q.push(a);}
		if(dat[ta+1][tb]==1) {dat[ta+1][tb]=-1; a.x=ta+1; a.y=tb; a.d=tc+1; q.push(a);}
	}
	a.x=fx; a.y=fy; a.d=1; q.push(a);
	dat[fx][fy]=-1;
	while(not q.empty())
	{
		a=q.front(); q.pop();
		ta=a.x; tb=a.y; tc=a.d;
		if(dat[ta-1][tb]==0) testexp(ta-1,tb,tc);
		if(dat[ta][tb-1]==0) testexp(ta,tb-1,tc);
		if(dat[ta][tb+1]==0) testexp(ta,tb+1,tc);
		if(dat[ta+1][tb]==0) testexp(ta+1,tb,tc);
		if(dat[ta-1][tb]==1) {dat[ta-1][tb]=-1; a.x=ta-1; a.y=tb; a.d=tc+1; q.push(a);}
		if(dat[ta][tb-1]==1) {dat[ta][tb-1]=-1; a.x=ta; a.y=tb-1; a.d=tc+1; q.push(a);}
		if(dat[ta][tb+1]==1) {dat[ta][tb+1]=-1; a.x=ta; a.y=tb+1; a.d=tc+1; q.push(a);}
		if(dat[ta+1][tb]==1) {dat[ta+1][tb]=-1; a.x=ta+1; a.y=tb; a.d=tc+1; q.push(a);}
	}
	printf("%d\n%d",c,m);
	return 0;
}