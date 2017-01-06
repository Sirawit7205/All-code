#include<stdio.h>
#include<string.h>

int chk()
{
	char str[25]={};
	int len,i,p=0,t=0,x=0,w=0;
	scanf("%s",str); len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='P') p++; else if(str[i]=='-') w++; else if(str[i]=='X') x++; else t++;
	}
	if(p==len) return 0;
	if(x!=0) return 2;
	if(t!=0) return 1;
	else return 3;
}

int main()
{
	int i,k,ret;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		ret=chk();
		printf("Case #%d: ",i);
		if(ret==0) printf("Yes\n");
		else if(ret==1) printf("No - Time limit exceeded\n");
		else if(ret==2) printf("No - Runtime error\n");
		else printf("No - Wrong answer\n");
	}
}