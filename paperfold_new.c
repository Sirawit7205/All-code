#include<stdio.h>

char num[2000]={};

int main()
{
	int a,i,j,d=0,right=0;
	scanf("%d",&a);
	if(a==1) {printf("1"); return 0;}
	num[0]='2';
	for(i=2;i<=a;i++)
	{
		for(j=0;j<=right;j++)
		{
			num[j]=num[j]+num[j]-48+d;
			if(num[j]>57) {num[j]-=10; d=1;} else d=0;
		}
		if(d==1) {right++; num[right]='1';} d=0;
	}
	for(i=right;i>=0;i--) if(i==0) printf("%c",num[i]-1); else printf("%c",num[i]);
	return 0;
}