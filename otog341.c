#include<stdio.h>
#include<stdlib.h>

int f[100005]={},ans=0;

int main()
{
	int i,n,t,a,b;
	scanf("%d %d",&n,&t);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&a,&b);
		f[b]=a;
	}
	for(i=1;i<=n;i++)
	{
		a=f[i];
		while(1)
		{
			if(abs(a-i)<=t&&a!=i) ans++;
			if(a==f[a]) break;
			a=f[a];
		}
	}
	printf("%d",ans);
	return 0;
}
