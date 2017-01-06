#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct a
{
	int x,y,l;
	bool operator < (const a&T) const 
	{
		return l>T.l;
	}
}b;

vector<a> v;
int h[200005]={};

int findh(int a)
{
	if(h[a]==a) return a;
	else return h[a]=findh(h[a]);
}

int main()
{
	int n,m,i,j,ta,tb;
	long long int tt=0,tc=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) h[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&b.x,&b.y,&b.l);
		v.push_back(b);
	}
	sort(v.begin(),v.end());
	for(i=0;i<m;i++)
	{
		ta=findh(v[i].x);
		tb=findh(v[i].y);
		if(ta!=tb) {h[ta]=tb; tc++; tt+=(v[i].l-1);}
		if(tc==n-1) break;
	}
	printf("%lld",tt);
	return 0;
}