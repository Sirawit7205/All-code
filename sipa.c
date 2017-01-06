#include<stdio.h>
#include<string.h>

int main()
{
	char dat[1005]={};
	int i, len, pos[300]={},c=0,d=0;
	scanf("%s",dat);
	len=strlen(dat);
	for(i=0;i<=len-4;i++)
	{
		if((dat[i]=='S'||dat[i]=='s')&&(dat[i+1]=='I'||dat[i+1]=='i')&&(dat[i+2]=='P'||dat[i+2]=='p')&&(dat[i+3]=='A'||dat[i+3]=='a'))
		{
			pos[c]=i;
			c++;
		}
	}
	//for(i=0;i<c;i++) printf("%d ",pos[i]); printf("\n");
	for(i=0;i<len;i++)
	{
		if(pos[d]==i) {printf("\""); d++;}
		if(i<len) printf("%c",dat[i]);
		if(pos[d-1]==i-3&&d>0) printf("\"");
	}
	printf("\n%d",c);
	return 0;
}