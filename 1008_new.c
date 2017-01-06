#include<stdio.h>

int f[256]={};

int main()
{
	int n,ta,tb,tc,i,j,mx=0,prev=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&ta,&tb,&tc);
		if(tc>mx) mx=tc;
		for(j=ta;j<tc;j++)
		{
			if(f[j]<tb) f[j]=tb;
		}
	}
	for(i=1;i<=mx+1;i++)
	{
		if(f[i]!=prev) {printf("%d %d ",i,f[i]); prev=f[i];}
	}
	return 0;
}