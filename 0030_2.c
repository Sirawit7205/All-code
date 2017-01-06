#include<stdio.h>
#include<string.h>

char prc[1000005]={};

int main()
{
	int i,ta=0,tb=0,len;
	scanf("%s",prc);
	len=strlen(prc);
	for(i=0;i<len;i++)
	{
		ta+=prc[i]-48; tb+=prc[i]-48;
		ta%=3; tb%=11;
		if(i!=len-1) {ta*=10; tb*=10;}
	}
	printf("%d %d",ta%3,tb%11);
	return 0;
}