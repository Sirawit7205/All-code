#include<stdio.h>

int d[60]={},n;

int chk(int l,int r)
{
	if(l==r) return d[l];
	
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	printf("%d",chk(1,n));
	return 0;
}