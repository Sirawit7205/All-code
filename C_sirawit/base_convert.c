#include<stdio.h>
#include<string.h>

char *baseconvert(int num, char *ans, int base)
{
	char current, buff[50]={};
	int res;	
	if(num==0)
		return ans;
	else
	{
		res=num%base;
		if(res>=0&&res<=9)
			current=res+48;
		else
			current=res+55;		
		sprintf(buff,"%c%s",current,ans);
		strcpy(ans,buff);
		baseconvert(num/base,ans,base);
	}
}

int main()
{
	char converted[50]={}, convertedB[50]={}, sprintfRes[50]={};
	int a;
	
	while(1)
	{
		printf("num> ");
		scanf("%d",&a);
		
		sprintf(sprintfRes,"%X",a);
		strcpy(convertedB,baseconvert(a,converted,16));
		printf("sprintf> %s\n",sprintfRes);
		printf("baseconvert> %s\n",converted);
		printf("backup> %s\n",convertedB);
	}
	
	return 0;
}