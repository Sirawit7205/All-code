#include<stdio.h>

int pos[60005]={},lst[30005]={};

int main()
{
	int range,amt,i,t=0,cur=0,m=0;
	scanf("%d %d",&amt,&range);
	for(i=0;i<=60000;i++)
	{
		if(i==t) {if(amt>=0) {if(amt!=0) scanf("%d",&t); cur++; lst[cur]=t; pos[i]=cur-1; amt--;} else break;}
		else pos[i]=cur-1;
	}
	for(i=1;i<=cur;i++)
	{
		if(lst[i]+range<=t) {if(m<pos[lst[i]+range]-pos[lst[i]]) m=pos[lst[i]+range]-pos[lst[i]];}
		else {if(m<pos[t]-pos[lst[i]]) m=pos[t]-pos[lst[i]];}
	}
	printf("%d",m);
	return 0;
}