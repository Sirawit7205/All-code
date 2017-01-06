#include<stdio.h>

int dat[10]={};

void swp(int a,int b)
{
	int i,t;
	t=dat[a];
	dat[a]=dat[b];
	dat[b]=t;
	for(i=0;i<5;i++) printf("%d ",dat[i]); printf("\n");
}

int main()
{
	int i,r=1;
	for(i=0;i<5;i++) scanf("%d",&dat[i]);
	while(!(dat[0]==1&&dat[1]==2&&dat[2]==3&&dat[3]==4&&dat[4]==5))
	{
		if(dat[0]>dat[1]&&r==1) swp(0,1);
		else if(dat[1]>dat[2]&&r==2) swp(1,2);
		else if(dat[2]>dat[3]&&r==3) swp(2,3);
		else if(dat[3]>dat[4]&&r==4) swp(3,4);
		if(r==4) r=1; else r++;
	}
	return 0;
}