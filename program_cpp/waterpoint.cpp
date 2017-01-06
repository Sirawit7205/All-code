#include<iostream>
#include<cstdio>

using namespace std;

int c[1000005]={};

int main()
{
	int i,n,p,j,ma=0,chk=0;
	long long int str=1,mid,en=0,cnt,dat=0,datb=0;
	scanf("%d %d",&n,&p);
	for(i=0;i<n;i++) {scanf("%d",&c[i]); if(c[i]>ma) ma=c[i];}
	en=ma; mid=(str+en)/2;
	while(str<en)
	{
		//printf("%lld %lld %lld",str,mid,en);
		cnt=0;
		for(j=0;j<n;j++) cnt+=c[j]/mid;
		//printf(" (%d)",cnt);
		if(cnt==p&&mid>dat) {chk=1; dat=mid;} else if(cnt>p&&mid>datb) datb=mid;
		if(cnt<p) {en=mid; mid=(str+en)/2;}
		else if(cnt>=p) {str=mid+1; mid=(str+en)/2;}
		//printf(" -> %lld %lld %lld\n",str,mid,en);
	}
	if(chk==1) printf("YES\n%lld",dat); else printf("NO\n%lld",datb);
	return 0;
}