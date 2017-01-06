#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct in{
	int a,b;
}ins;

bool cmp(in const&l, in const&r)
{
	if(l.a!=r.a) return l.a < r.a;
	else return l.b < r.b;
}

vector<in> q;

int main()
{
	int n,m,i,j,ta,tb,preva=0,prevb=0,ans=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&ta,&tb);
		ins.a=ta; ins.b=tb; q.push_back(ins);
	}
	sort(q.begin(),q.end(),&cmp);
	if(n==0) return 0;
	else if(m==0) {for(i=1;i<=n;i++) printf("%d 0\n",i); return 0;}
	preva=q[0].a; prevb=q[0].b; ans=1;
	for(i=1;i<m;i++)
	{
		if(q[i].a!=preva) 
		{
			printf("%d %d\n",preva,ans);
			for(j=preva+1;j<=q[i].a-1;j++) printf("%d 0\n",j);
			preva=q[i].a; prevb=q[i].b; ans=1;
		}
		else if(q[i].a==preva&&q[i].b!=prevb) {prevb=q[i].b; ans++;}
	}
	printf("%d %d\n",preva,ans);
	if(preva!=n) for(j=preva+1;j<=n;j++) printf("%d 0\n",j);
	return 0;
}
