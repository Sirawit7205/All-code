#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int num[22505]={};

int main()
{
	int n,i;
	long long int cnt=0,diff=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {scanf("%d",&num[i]); cnt+=num[i];}
	sort(num,num+n);
	diff=cnt;
	for(i=0;i<n-1;i++)
	{
		//printf("i: %d DIFF: %lld\n",i,diff);
		cnt+=diff;
		diff-=num[i];
	}
	printf("%lld",cnt);
	return 0;
}