#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int i,len;
	char a[1005]={};
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]!='E'&&a[i]!='O'&&a[i]!='I'&&a[i]!='C') printf("%c",a[i]);
	}
	return 0;
}