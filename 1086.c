#include<stdio.h>

int q[10005]={};

int main()
{
	int n,k,a,i,j,t,mx=0,pre,c=1,x;
	scanf("%d %d %d",&n,&k,&a);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		for(j=c;j<=c+t-1;j++) q[j]=i;
		c=j;
	}
	c--;
	for(i=1;i<=c;i++)
	{
		if(a*(k-1)+i>c) break;
		t=1; pre=q[i];
		for(j=i;j<=a*(k-1)+i;j+=a) if(q[j]!=pre) {pre=q[j]; t++;}
		if(t>mx) {x=i; mx=t;}
	}
	printf("%d %d",x,mx);
	return 0;
}
