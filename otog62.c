#include<stdio.h>

int n,dat[15]={},ans=0;

void fd(int lim)
{
	int i,j,x[10]={},mult=1,div=1,t=1,m=0;
	x[0]=9-lim;
	for(i=1;i<=9;i++) mult*=i;
	for(i=1;i<=lim;i++) x[dat[i]]++;
	for(i=0;i<=9;i++) {t=1; for(j=1;j<=x[i];j++) t*=j; div*=t;}
	ans+=mult/div;
}

void perm(int lim, int cur, int pre, int cnt)
{
	int i;
	if(cur>lim) {if(cnt==n) fd(lim); return;}
	for(i=dat[cur-1];i<=9;i++)
	{
	    if(i==0) continue;
		if(cnt+i<=n) {dat[cur]=i; perm(lim,cur+1,i,cnt+i);} else return;
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=2;i<=9;i++) perm(i,1,0,0);
	if(n==1) ans+=10; else if(n>1&&n<10) ans+=9;
	printf("%d",ans);
	return 0;
}
