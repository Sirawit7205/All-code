#include<stdio.h>
#include<string.h>

int main()
{
	int tempa=0,tempb=0,tempc=0,len,i;
	char a[1000005]={};
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		tempa+=a[i]-48;
		if(i%2==0) tempb+=a[i]-48; else tempc+=a[i]-48;
	}
	tempa%=3; tempc-=tempb; tempc%=11;
	if(tempc<0) tempc+=11;
	printf("%d %d",tempa,tempc);
	return 0;
}