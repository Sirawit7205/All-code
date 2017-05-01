#include<stdio.h>

int main()
{
	int a,b;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	if(a<b) 
	{
		printf("The maximum value is %d.\n",b);
		printf("The minimum value is %d.",a);
	}	
	else
	{
		printf("The maximum value is %d.\n",a);
		printf("The minimum value is %d.",b);
	}	
	return 0;
}