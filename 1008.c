#include<stdio.h>

int main()
{
	int i,j,tt,l,r,h,m=0,c=0,dat[256][260]={};
	scanf("%d",&tt);
	for(i=0;i<tt;i++)
	{
		scanf("%d %d %d",&l,&h,&r);
		if(dat[l][0]<h) dat[l][0]=h;
		if(r>m) m=r;
		dat[l][dat[r+1][1]+2]=h; dat[r+1][1]++;
	}
	//for(i=0;i<=m;i++) printf("%d %d ",dat[i][0]); printf("\n");
	for(i=1;i<=m;i++)
	{
		if(i==r) {printf("%d 0",i); return 0;}
		if(dat[i][1]!=0)
		{
			for(j=2;j<=2+dat[i][1];j++)
			{
				if(dat[i][j]==c) c=0;
			}
		}
		if(dat[i][0]>c) {c=dat[i][0]; printf("%d %d ",i,dat[i][0]);}
	}
	return 0;
}