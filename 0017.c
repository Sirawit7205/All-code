#include<stdio.h>

int c[5]={},fn[5]={},ln[5]={},max=0;

void cval()
{
	int a=fn[0]-fn[2],b=fn[1]-fn[3];
	if(a>=0&&b<=0)
	{
		if((fn[0]-(fn[0]-fn[2]))*fn[1]>max) max=(fn[0]-(fn[0]-fn[2]))*fn[1];
	}
}

void recur(int a)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		if(c[i]==0) {fn[a]=ln[i]; c[i]=1; recur(a+1); c[i]=0;}
		if(a==4) {for(j=0;j<4;j++) cval(); return;}
	}
}

int main()
{
	scanf("%d %d %d %d",&ln[0],&ln[1],&ln[2],&ln[3]);
	recur(0);
	printf("%d",max);
	return 0;
}