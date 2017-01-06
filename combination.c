#include<stdio.h>

int use[15]={},a,b,c,ins[15]={},x=0,br=1;

void comb(int s,int cn)
{
	int i,j;
	if(x==1) return;
	if(cn>b) {if(br==c) {for(j=1;j<=b;j++) printf("%d ",ins[j]); x=1; return;} else {br++; return;}}
	for(i=s;i<=a;i++)
	{
		if(use[i]==0) {use[i]=1; ins[cn]=i; comb(i+1,cn+1); use[i]=0;}
	}
}

int main()
{
	int i;
	scanf("%d %d %d",&a,&b,&c);
	comb(1,1);
	return 0;
}