#include<stdio.h>
#include<string.h>

int c[10]={},t[5]={};
char dat[1005]={};

int main()
{
	int n,l,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		c[1]=1; c[2]=2; c[3]=3; c[4]=5; c[5]=4; c[6]=6; //UP FRONT LEFT BACK RIGHT DOWN
		scanf("%s",dat); l=strlen(dat);

		for(j=0;j<l;j++)
		{
			if(dat[j]=='F') {t[1]=c[2]; t[2]=c[6]; t[3]=c[4]; t[4]=c[1]; c[2]=t[4]; c[1]=t[3]; c[4]=t[2]; c[6]=t[1];}
			else if(dat[j]=='B') {t[1]=c[2]; t[2]=c[6]; t[3]=c[4]; t[4]=c[1]; c[2]=t[2]; c[6]=t[3]; c[4]=t[4]; c[1]=t[1];}
			else if(dat[j]=='L') {t[1]=c[3]; t[2]=c[6]; t[3]=c[5]; t[4]=c[1]; c[3]=t[4]; c[1]=t[3]; c[5]=t[2]; c[6]=t[1];}
			else if(dat[j]=='R') {t[1]=c[3]; t[2]=c[6]; t[3]=c[5]; t[4]=c[1]; c[3]=t[2]; c[6]=t[3]; c[5]=t[4]; c[1]=t[1];}
			else if(dat[j]=='D') {t[1]=c[3]; t[2]=c[2]; t[3]=c[5]; t[4]=c[4]; c[3]=t[4]; c[4]=t[3]; c[5]=t[2]; c[2]=t[1];}
			else if(dat[j]=='C') {t[1]=c[3]; t[2]=c[2]; t[3]=c[5]; t[4]=c[4]; c[3]=t[2]; c[2]=t[3]; c[5]=t[4]; c[4]=t[1];}
		}
		printf("%d ",c[2]);
	}
	return 0;
}
