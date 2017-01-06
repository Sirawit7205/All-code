#include<stdio.h>

int sm[255][255]={};

int main()
{
	int i,j,n,m,t;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&t);
			if(sm[i-1][j]>=sm[i][j-1]) sm[i][j]=t+sm[i-1][j];
			else sm[i][j]=t+sm[i][j-1];
		}
	}
	printf("%d",sm[n][m]);
	return 0;
}