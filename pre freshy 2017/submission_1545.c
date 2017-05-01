#include<stdio.h>

int main()
{
	int num[15]={},i,tempnum;
	char text;
	for(i=0;i<10;i++)
	{
		printf("Enter number: ");
		scanf("%d",&num[i]);
	}
	printf("What kind of number that you want to filter out? (o = odd, e = even): ");
	scanf(" %c",&text);
	printf("The filtered numbers are ...\n");
	for(i=0;i<10;i++)
	{
		if(num[i]<0)
			tempnum = num[i]*-1;
		else
			tempnum = num[i];
		if(text == 'o' && tempnum%2==0) printf("%d\n",num[i]);
		if(text == 'e' && tempnum%2==1) printf("%d\n",num[i]);
	}
	return 0;
}