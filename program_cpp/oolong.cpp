#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct stk{
	int ind;
	long long int x,y;
}dat[50005]={};

bool  cmpa(stk a,stk b) {return a.x<b.x;}
bool  cmpb(stk a,stk b) {return a.y<b.y;}

int main()
{
	int i,n,k,cnt=0;
	long long int m;
	scanf("%d %d %lld",&n,&k,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&dat[i].x,&dat[i].y);
	}
	sort(dat,dat+n,cmpb);
	for(i=1;i<=k;i++)
	{
		if(m<=0||m-dat[i-1].y<0) break;
		dat[i-1].ind=i;
		m-=dat[i-1].y;
		cnt++;
		//printf("use cp: %d\n",dat[i-1].x);
	}
	sort(dat,dat+n,cmpa);
	for(i=0;i<n;i++)
	{
		//printf("cp_chk: %d x:%lld y: %lld m: %lld\n",dat[i].ind,dat[i].x,dat[i].y,m);
		if(dat[i].ind<=k&&dat[i].ind!=0) continue;
		if(m<=0||m-dat[i].x<0) break;
		m-=dat[i].x;
		cnt++;
	}
	printf("%d",cnt);
	//for(i=0;i<n;i++) printf("%lld %lld\n",dat[i].x,dat[i].y);
	//getchar(); getchar(); //STOPPER
	return 0;
}