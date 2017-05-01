#include<stdio.h>

int main()
{
	int num,cnt=0;
	double sum=0;
	while(1)
	{
		printf("Enter number: ");
		scanf("%d",&num);
		if(num<0) break;
		cnt++;
		sum+=num;
	}
	printf("There are %d numbers.\nThe average value is %.3f",cnt,sum/cnt);
	return 0;
}