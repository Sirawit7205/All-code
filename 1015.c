#include<stdio.h>

int dat[20][20]={},cln[20][20]={},ans=0,c=0;

void chk(int i,int j,int t)
{
	c++; dat[i][j]=0;
	if(dat[i-1][j]==t) chk(i-1,j,t);
	if(dat[i][j-1]==t) chk(i,j-1,t);
	if(dat[i+1][j]==t) chk(i+1,j,t);
	if(dat[i][j+1]==t) chk(i,j+1,t);
	return;
}

int err(int i,int j,int t)
{
	if(cln[i-2][j]==t&&cln[i-1][j]==t||cln[i+1][j]==t&&cln[i+2][j]==t||cln[i][j-2]==t&&cln[i][j-1]==t||cln[i][j+1]==t&&cln[i][j+2]==t) return 1;
	else if(cln[i-1][j]==t&&cln[i+1][j]==t||cln[i][j-1]==t&&cln[i][j+1]==t) return 1;
	else return 0;
}

int main()
{
	int amt,i,j;
	scanf("%d",&amt);
	for(i=2;i<=amt+1;i++)
	{for(j=2;j<=amt+1;j++)
	{scanf("%d",&dat[i][j]); cln[i][j]=dat[i][j];}}
	for(i=2;i<=amt+1;i++)
	{
		for(j=2;j<=amt+1;j++)
		{
			if(dat[i][j]!=0) 
				{
					c=0; 
					chk(i,j,dat[i][j]); 
					if(c==3) {if(err(i,j,cln[i][j])==0) ans++;}
				}
		}
	}
	printf("%d",ans);
	return 0;
}