#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

int dat[2005][2005]={},qsd[2005][2005]={},qsr[2005][2005]={},qsdl[2005][2005]={},qsdr[2005][2005]={},m,n;

int main()
{
	int k,i,j,b=0,t;
	long long int ma=INT_MIN;
	scanf("%d %d %d",&m,&n,&k);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++) scanf("%d",&dat[i][j]);
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++) {qsd[i][j]=dat[i][j]+qsd[i-1][j]; qsr[i][j]=dat[i][j]+qsr[i][j-1]; qsdl[i][j]=dat[i][j]+qsdl[i-1][j-1]; qsdr[i][j]=dat[i][j]+qsdr[i-1][j+1];}
	}
	for(i=1;i<=k;i++) b+=qsdl[k][k-i+1];
	if(b>ma) ma=b;
	for(i=1;i<=m-k+1;i++)
	{
		t=b;
		for(j=2;j<=n-k+1;j++)
		{
			b-=qsd[i+k-1][j-1]-qsd[i-1][j-1]; b+=qsdl[i+k-1][j+k-1]-qsdl[i-1][j-1];
			if(b>ma) ma=b;
		}
		b=t+qsr[i+k][k]-qsdl[i+k-1][k];
		if(b>ma&&i<m-k+1) ma=b;
	}
	b=0;
	for(i=1;i<=k;i++) b+=qsdr[k][i]-qsdr[i-1][k+1];
	if(b>ma) ma=b;
	for(i=1;i<=m-k+1;i++)
	{
		t=b;
		for(j=2;j<=n-k+1;j++)
		{
			b+=qsd[i+k-1][j+k-1]-qsd[i-1][j+k-1]; b-=qsdr[i+k-1][j-1]-qsdr[i-1][j+k-1];
			if(b>ma) ma=b;
		}
		b=t+qsr[i+k][k]-(qsdr[i+k-1][1]-qsdr[i-1][k+1]);
		if(b>ma&&i<m-k+1) ma=b;
	}
	printf("%lld",ma);
	return 0;
}