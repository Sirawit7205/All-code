#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct x{
	int a,b,l;
	bool operator<(const x&T)const{
		return l > T.l;
	}
}aa;

vector<x> q;
int head[200005]={};
long long int ans=0;

int fhead(int n)
{
	if(head[n]==n) return n;
	else return head[n]=fhead(head[n]);
}

int main()
{
	int i,n,m,ta,tb,tc,cnt=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&aa.a,&aa.b,&aa.l); q.push_back(aa);		
	}	
	sort(q.begin(),q.end());
	for(i=1;i<=n;i++) head[i]=i;
	for(i=0;i<m;i++)
	{
		if(cnt==n-1) break;
		aa=q[i]; ta=aa.a; tb=aa.b; tc=aa.l;
		ta=fhead(ta); tb=fhead(tb);
		if(ta==tb) continue;
		else head[tb]=ta;
		ans+=tc-1; cnt++;
	}
	printf("%lld",ans);
	return 0;
}
