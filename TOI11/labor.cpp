#include<iostream>
#include<cstdio>

using namespace std;

int dat[1000005]={},m;

int main()
{
	int i,j,ma=0;
	long long int str=1,mid,en,n,t,x;
	scanf("%d %lld",&m,&n);
	for(i=0;i<m;i++) {scanf("%d",&dat[i]);}// if(dat[i]>ma) ma=dat[i];}
	en=1000000*n; mid=(en+str)/2;
	while(str<en)
	{
		x=0;
		for(j=0;j<m;j++) x+=mid/dat[j];
		if(x>=n) {en=mid; mid=(en+str)/2;}
		else if(x<n) {str=mid+1; mid=(en+str)/2;}
		//printf("%lld: %lld %lld %lld\n",t,str,mid,en);
	}
	printf("%lld",mid);
	return 0;
}
