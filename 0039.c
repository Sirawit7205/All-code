#include<stdio.h>

int res[10]={},use[10]={},ans[10]={},n;

void perm(int lv)
{
	int i;
	if(lv>n) {for(i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(use[i]!=1) {use[i]=1; ans[lv]=i; perm(lv+1); use[i]=0;}
		}
	}
}

int main()
{
	int m,i,t;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&t);
		res[t]=1;
	}
	for(i=1;i<=n;i++) {if(res[i]==0) {ans[1]=i; use[i]=1; perm(2); use[i]=0;}}
	return 0;
}