#include<iostream>
#include<cstdio>

using namespace std;

int qsum[1005][1005]={};

int main()
{
	int r,c,i,j,k,sta;
	char t;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf(" %c",&t);
			qsum[i][j]=qsum[i-1][j]+qsum[i][j-1]-qsum[i-1][j-1]+(t-48);
		}
	}
	sta=min(r,c);
	for(i=sta;i>=1;i--)
	{
		for(j=i;j<=r;j++)
		{
			for(k=i;k<=c;k++)
			{
				//printf("%d %d %d\n",i,j,k);
				//printf("%d %d %d\n",j,k,qsum[j][k]-qsum[j-i][k]-qsum[j][k-i]+qsum[j-i][k-i]);
				if(qsum[j][k]-qsum[j-i][k]-qsum[j][k-i]+qsum[j-i][k-i]==i*i) {printf("%d",i);  return 0;}
			}
		}
	}
	return 0;
}