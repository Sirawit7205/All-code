#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

int dat[105]={},cal[105][105]={},m[105][105]={};

int main()
{
	int n,i,j,k,l,t;
	scanf("%d",&n);
	for(i=0;i<=n;i++) scanf("%d",&dat[i]);
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			//printf("J: %d\n",j);
			cal[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				t=cal[i][k]+cal[k+1][j]+(dat[i-1]*dat[j]*dat[k]);
				if(t<cal[i][j])
				{
					//printf("MIN[%d,%d]: %d\n",i,j,t);
					cal[i][j]=t;
					m[i][j]=k;
				}
			}
		}
	}
	printf("%d ",cal[1][n]);
	return 0;
}