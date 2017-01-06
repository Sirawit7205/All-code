#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int i,j,a;
	scanf("%d",&a);
	for(i=0;i<=a/2;i++)
	{
		for(j=0;j<(a/2)-i;j++) printf("-");
		for(j=0;j<=i*2;j++) printf("*");
		for(j=0;j<(a/2)-i;j++) printf("-");
		printf("\n");
	}
	for(i=(a/2)-1;i>=0;i--)
	{
		for(j=0;j<(a/2)-i;j++) printf("-");
		for(j=0;j<=i*2;j++) printf("*");
		for(j=0;j<(a/2)-i;j++) printf("-");
		printf("\n");
	}
	return 0;
}