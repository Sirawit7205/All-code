#include<stdio.h>

int p[100005]={},c[100005]={},t=0,n,m;

int findh(int a)
{
	if(p[a]==a) return a;
	else return p[a]=findh(p[a]);
}

int main()
{
	int ta,tb,i,j,t;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) {scanf("%d",&c[i]); p[i]=i;}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&ta,&tb);
		if(ta>tb) {t=ta; ta=tb; tb=t;}
		ta=findh(ta); tb=findh(tb);
		if(ta==tb) {printf("-1\n"); continue;} 
		if(c[ta]>=c[tb])
		{
			c[ta]+=c[tb]/2;
			p[tb]=ta;
			printf("%d\n",ta);
		}
		else
		{
			c[tb]+=c[ta]/2;
			p[ta]=tb;
			printf("%d\n",tb);
		}
	}
	return 0;
}
