#include<stdio.h>
#include<string.h>

int main()
{
	int i,len;
	char str[25]={},buffer[25]={};
	printf("Enter string: ");
	fgets(buffer,20,stdin);
	sscanf(buffer,"%s",str);
	len = strlen(str);
	printf("The reversed string is ");
	for(i=len-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
	printf(".");
	return 0;
}