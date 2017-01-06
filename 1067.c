#include<stdio.h>

bool chk[20][100][100]={};
int dat[105][105]={};

int main()
{
	int n,m,k,i,j,sa,sb;
	scanf("%d %d %d",&m,&n,&k);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++) scanf("%d",&dat[i][j]);
	}
	for(i=0;i<k;i++)
	{
		scanf("%d %d",&sb,&sa); sa--; sb--;
		while(1)
		{
			if(chk[i][sa][sb]==true) {printf("NO\n"); break;}
			else chk[i][sa][sb]=true;
			if(dat[sa][sb]==1)
			{
				if(sa==0) {printf("N\n"); break;}
				else sa--;
			}
			else if(dat[sa][sb]==2)
			{
				if(sb==m-1) {printf("E\n"); break;}
				else sb++;
			}
			else if(dat[sa][sb]==3)
			{
				if(sa==n-1) {printf("S\n"); break;}
				else sa++;
			}
			else
			{
				if(sb==0) {printf("W\n"); break;}
				else sb--;
			}
		}
	}
	return 0;
}