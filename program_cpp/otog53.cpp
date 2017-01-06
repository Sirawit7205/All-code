#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct act
{
	int num,h;
	bool operator<(const act&T) const {return h<T.h;}
}inst;

priority_queue<act> q;
int chk[100005]={},hc[100005]={},n,m;

int main()
{
	int i,t,c=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		inst.num=i; inst.h=t; q.push(inst);
		hc[i]=t;
	}
	chk[0]=1; chk[n+1]=1;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&t);
		c=0;
		if(!q.empty())
		{
			while(1)
			{
				if(q.empty()) break;
				inst=q.top();
				if(inst.h<=t) break;
				else
				{
					q.pop();
					if(chk[inst.num]==0) {chk[inst.num]=1; c++;} else continue;
					if(chk[inst.num-1]==0&&hc[inst.num-1]<=t) {chk[inst.num-1]=1; c++;}
					if(chk[inst.num+1]==0&&hc[inst.num+1]<=t) {chk[inst.num+1]=1; c++;}
				}
			}
			printf("%d\n",c);
		}
		else {printf("0\n"); continue;}
	}
	return 0;
}