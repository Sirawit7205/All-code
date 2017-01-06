#include<iostream>
#include<cstdio>

using namespace std;

int qsum[1005][1005]={},ans[1005][1005]={};

int main()
{
	int r,c,i,j,ma=0,tt;
	char t;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf(" %c",&t);
			qsum[i][j]=t-48;
		}
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(qsum[i][j]==0) ans[i][j]=0;
			else
			{
				tt=min(ans[i-1][j],ans[i][j-1]);
				tt=min(tt,ans[i-1][j-1]);
				tt++;
				ans[i][j]=tt;
				if(tt>ma) ma=tt;
			}
		}
	}
	printf("%d",ma);
	return 0;
}