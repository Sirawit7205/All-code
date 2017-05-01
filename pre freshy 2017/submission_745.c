#include<stdio.h>

int main()
{
	int num[15]={},i;
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
		if(text == 'o' && num[i]%2==0) printf("%d\n",num[i]); //filter odd display even
		if(text == 'e' && num[i]%2==1) printf("%d\n",num[i]); //filter even display odd
	}
	return 0;
}