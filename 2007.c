#include<stdio.h>

char m[3000005]={},target[3005]={};
int tas[55]={},mas[55]={},ans=0,acnt=0,bcnt=0;

void asc()
{
	int i;
	for(i=0;i<52;i++) if(tas[i]!=mas[i]) return;
	ans++;
}

int main()
{
	int tl,ml,i;
	scanf("%d %d",&tl,&ml);
	scanf("%s",target);
	scanf("%s",m);
	for(i=0;i<tl;i++)
	{
		acnt+=target[i]; bcnt+=m[i];
		if(target[i]>=65&&target[i]<=90) tas[target[i]-65]++; else tas[target[i]-71]++;
		if(m[i]>=65&&m[i]<=90) mas[m[i]-65]++; else mas[m[i]-71]++;
	}
	for(i=tl;i<=ml;i++)
	{
		if(acnt==bcnt) asc();
		bcnt-=m[i-tl]; bcnt+=m[i];
		if(m[i]>=65&&m[i]<=90) mas[m[i]-65]++; else mas[m[i]-71]++;
		if(m[i-tl]>=65&&m[i-tl]<=90) mas[m[i-tl]-65]--; else mas[m[i-tl]-71]--;
	}
	printf("%d",ans);
	return 0;
}