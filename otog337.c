#include<stdio.h>
#include<limits.h>

int f[1005][1005]={}, ma[1005][3]={}, mb[1005][3]={}, ans=INT_MAX;

int main()
{
	int i,j,n,m,x,y,t;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) scanf("%d",&f[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		x=INT_MAX,y=INT_MAX,t=0;
		for(j=1;j<=m;j++) if(f[i][j]<x) {x=f[i][j]; t=j;}
		for(j=1;j<=m;j++) if(f[i][j]>=x&&f[i][j]<y&&j!=t) y=f[i][j];
		ma[i][0]=x; ma[i][1]=y;
	}
	for(i=1;i<=m;i++)
	{
		x=INT_MAX,y=INT_MAX,t=0;
		for(j=1;j<=n;j++) if(f[j][i]<x) {x=f[j][i]; t=j;}
		for(j=1;j<=n;j++) if(f[j][i]>=x&&f[j][i]<y&&j!=t) y=f[j][i];
		mb[i][0]=x; mb[i][1]=y;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			t=f[i][j];
			if(f[i][j]==ma[i][0]) t+=ma[i][1]; else t+=ma[i][0];
			if(f[i][j]==mb[j][0]) t+=mb[j][1]; else t+=mb[j][0];
			if(t<ans) ans=t;
		}
	}
	printf("%d",ans);
	return 0;
}