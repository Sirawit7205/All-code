#include<cstdio>
#include<algorithm>

using namespace std;

int a[1000005]={},b[1000005]={},c[15]={},d[15]={},ansa[15]={},ansb[15]={},tta=0,ttb=0;

int main()
{
	int i,j,p,m,k,min=1,mina=0,t,ta,x;
	scanf("%d %d %d",&p,&m,&k);
	for(i=0;i<k;i++) {scanf("%d",&c[i]); d[i]=c[i];}
	sort(c,c+k);
	for(i=1;i<=m;i++)
	{
		t=10000000;
		if(c[mina+1]==i) {mina++;}
		for(j=0;j<=mina;j++)
		{
			if(a[i-c[j]]+1<t) {t=a[i-c[j]]+1; ta=j;}
		}
		a[i]=t; b[i]=ta;
		//printf("%d %d\n",a[i],b[i]);
	}
	t=10000000;
	for(i=m;i>=p;i--)
	{
		if(a[i]+a[i-p]<t) {x=i; t=a[i]+a[i-p]; tta=a[i]; ttb=a[i-p];}
	}
	printf("%d %d\n",tta,ttb);
	i=x; j=x-p;
	while(1)
	{
		if(i==0) break;
		ansa[b[i]]++;
		i-=c[b[i]];
	}
	while(1)
	{
		if(j==0) break;
		ansb[b[j]]++;
		j-=c[b[j]];
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(c[j]==d[i]) printf("%d ",ansa[j]);
		}
	}
	printf("\n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(c[j]==d[i]) printf("%d ",ansb[j]);
		}
	}
	return 0;
}