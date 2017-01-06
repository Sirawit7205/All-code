#include<stdio.h>

long long int n, p[1005]={}, qsum[1005]={};

int main()
{
	int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(i=1;i<=n;i++)
	{
		if(i==1) {qsum[i]=2; continue;}
		qsum[i]=(1000000007+qsum[i-1]-qsum[p[i]-1]+qsum[i-1]+2)%1000000007;
	}
	printf("%lld",qsum[n]);
	return 0;
}