#include<stdio.h>
#include<stdlib.h>

int s[15]={},b[15]={},use[15]={},ans[15]={},n,mi=1000000005;

void cal(int lim)
{
	int i,ta=1,tb=0;
	for(i=1;i<=lim;i++)
	{
		ta*=s[ans[i]]; tb+=b[ans[i]];
	}
	if(abs(ta-tb)<mi) mi=abs(ta-tb);
}

void comb(int cur, int cnt, int lim)
{
	int i;
	if(cnt>lim) {cal(lim); return;}
	for(i=cur;i<=n;i++)
	{
		if(use[i]==0) {use[i]=1; ans[cnt]=i; comb(cur+1,cnt+1,lim); use[i]=0;}
	}
	
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d %d",&s[i],&b[i]);
	for(i=1;i<=n;i++) comb(1,1,i);
	printf("%d",mi);
	return 0;
}