#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
	int x,y;
}b;

char dat[2005][2005]={};
queue<a> q;

int main()
{
	int i,j,m,n,ans=0,ta,tb;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++) scanf(" %c",&dat[i][j]);
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dat[i][j]=='1')
			{
				//printf("%d %d\n",i,j);
				dat[i][j]='0';
				ans++;
				b.x=i; b.y=j; q.push(b);
				while(not q.empty())
				{
					b=q.front(); q.pop();
					ta=b.x; tb=b.y;
					dat[ta][tb]='0';
					if(dat[ta-1][tb-1]=='1') {dat[ta-1][tb-1]='0'; b.x=ta-1; b.y=tb-1; q.push(b);}
					if(dat[ta-1][tb]=='1') {dat[ta-1][tb]='0'; b.x=ta-1; b.y=tb; q.push(b);}
					if(dat[ta-1][tb+1]=='1') {dat[ta-1][tb+1]='0'; b.x=ta-1; b.y=tb+1; q.push(b);}
					if(dat[ta][tb-1]=='1') {dat[ta][tb-1]='0'; b.x=ta; b.y=tb-1; q.push(b);}
					if(dat[ta][tb+1]=='1') {dat[ta][tb+1]='0'; b.x=ta; b.y=tb+1; q.push(b);}
					if(dat[ta+1][tb-1]=='1') {dat[ta+1][tb-1]='0'; b.x=ta+1; b.y=tb-1; q.push(b);}
					if(dat[ta+1][tb]=='1') {dat[ta+1][tb]='0'; b.x=ta+1; b.y=tb; q.push(b);}
					if(dat[ta+1][tb+1]=='1') {dat[ta+1][tb+1]='0'; b.x=ta+1; b.y=tb+1; q.push(b);}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}