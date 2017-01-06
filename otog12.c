#include<stdio.h>

int main()
{
	int trg,i,j,cnt[10]={};
	scanf("%d",&trg);
	if(trg==0) {printf("0"); return 0;}
	else if(trg==1) {printf("1"); return 0;}
	for(i=9;i>1;i--)
	{
		while(trg%i==0) {cnt[i]++; trg/=i;}
	}
	if(trg>1) {printf("-1"); return 0;} 
	for(i=2;i<=9;i++) for(j=1;j<=cnt[i];j++) printf("%d",i);
	return 0;
}