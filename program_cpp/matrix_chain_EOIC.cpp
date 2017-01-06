#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

int dat[105]={},cal[105][105]={},m[105][105]={},p=1;

void prt(int a,int b)
{
	if(a==b) {printf("A%d",p); p++; return;}
	printf("(");
	prt(a,m[a][b]);
	printf("x");
	prt(m[a][b]+1,b);
	printf(")");
}

int main()
{
	int n,i,j,k,l,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d %d",&dat[i-1],&dat[i]);
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
	printf("%d\n",cal[1][n]);
	prt(1,n);
	//for(i=1;i<=n;i++) {for(j=1;j<=n;j++) printf("%d ",m[i][j]); printf("\n");}
	return 0;
}