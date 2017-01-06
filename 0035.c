#include<stdio.h>
#include<stdlib.h>

int use[105]={},ans[5]={},coorx[105]={},coory[105]={},n;
double mx=0;

void comb(int a,int b)
{
	int i;
	double t;
	if(b>3)
	{
		t=abs((coorx[ans[1]]*coory[ans[2]])+(coorx[ans[2]]*coory[ans[3]])+(coorx[ans[3]]*coory[ans[1]])-(coorx[ans[1]]*coory[ans[3]])-(coorx[ans[2]]*coory[ans[1]])-(coorx[ans[3]]*coory[ans[2]]));
		t/=2;
		if(t>mx) mx=t;
		return;
	}
	for(i=a;i<=n;i++)
	{
		if(use[i]==0) {ans[b]=i; use[i]=1; comb(i+1,b+1); use[i]=0;}
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d %d",&coorx[i],&coory[i]);
	comb(1,1);
	printf("%.3f",mx);
	return 0;
}
