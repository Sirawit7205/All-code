#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int num[100005]={};

int main()
{
	int m,n,i,t;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++) scanf("%d",&num[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(t<num[0]) printf("-1\n");
		//else if(t==num[0]) printf("0\n");
		else printf("%d\n",(upper_bound(num,num+m,t)-num)-1);
	}
	return 0;
}