#include<stdio.h>

int num[100005]={},n;
long long int qsum[100005]={};

int bs(int k,int m)
{
	int mid,l=1,r=n;
	mid=(l+r)/2;
	while(l<=r)
	{
		if(num[mid]==k) return mid;
		else if(num[mid]<k) l=mid+1;
		else if(num[mid]>k) r=mid-1;
		mid=(l+r)/2;
	}
	if(m==1&&num[mid]<k) return mid+1;
	else if(m==2&&num[mid]>k) return mid-1;
	else return mid;
}

int main()
{
	int t,k,i,l,r,ta,tb,tc;
	scanf("%d %d %d",&n,&t,&k);
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&ta,&tb,&tc);
		l=bs(ta,1); r=bs(tb,2); //printf("RET A:%d %d\n",l,r);
		qsum[l]+=tc; qsum[r+1]+=tc*-1;
	}
	for(i=1;i<=n;i++) qsum[i]+=qsum[i-1];
	for(i=1;i<=n;i++) qsum[i]+=qsum[i-1];
	for(i=1;i<=k;i++)
	{
		scanf("%d %d",&ta,&tb);
		l=bs(ta,1); r=bs(tb,2); //printf("RET B:%d %d\n",l,r);
		printf("%lld\n",qsum[r]-qsum[l-1]);
	}
	return 0;
}
