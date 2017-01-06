#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int m,n,i,j,cur=65;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(cur>90) cur=65;
			printf("%c",cur);
			cur++;
		}
		printf("\n");
	}
	return 0;
}