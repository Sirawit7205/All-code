#include<stdio.h>
#include<stdlib.h>

int f[1005]={}, c[1005]={};

int main()
{
	int n,i,j,ans=0,md,mpa,mpb,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&f[i]);
	for(i=n;i>1;i-=2)
	{
		md=-1;
		for(j=0;j<n-1;j+=0)
		{
			k=j;
			while(1) if(c[k]==1) {k++; continue;} else break;
			l=k+1;
			while(1) if(c[l]==1) {l++; continue;} else break;
			if(l>n-1) break;
			if(abs(f[k]-f[l])>md) {md=abs(f[k]-f[l]); mpa=k; mpb=l;}
			j=k+1;
		}
		//printf("select %d and %d with sum %d\n",mpa,mpb,abs(f[mpa]-f[mpb]));
		ans+=abs(f[mpa]-f[mpb]);
		c[mpa]=1; c[mpb]=1;
	}
	printf("%d",ans);
	return 0;
}