#include<iostream>
#include<cstdio>

using namespace std;

int dat[1005][1005]={},qsum[1005][1005]={};

int main()
{
	int ta,tb,m,n,i,j,k,lpa,lpb,upa,upb;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++) {scanf("%d %d",&ta,&tb); dat[ta+1][tb+1]++;}
	for(i=1;i<=1001;i++)
	{
		for(j=1;j<=1001;j++) qsum[i][j]=qsum[i-1][j]+qsum[i][j-1]+dat[i][j]-qsum[i-1][j-1];
	}
/* for(i=1;i<=20;i++)
	{
		for(j=1;j<=20;j++) printf("%d ",qsum[i][j]);
		printf("\n");
	} */
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&ta,&tb,&k);
		lpa=ta-k+1; lpb=tb-k+1; upa=ta+k+1; upb=tb+k+1;
		if(lpa<1) lpa=1; if(lpb<1) lpb=1; if(upa>1001) upa=1001; if(upb>1001) upb=1001;
		printf("%d\n",qsum[upa][upb]-qsum[lpa-1][upb]-qsum[upa][lpb-1]+qsum[lpa-1][lpb-1]);
	}
	return 0;
}