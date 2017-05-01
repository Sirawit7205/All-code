#include<stdio.h>

int main()
{
	int i, amin, amax;
	char name[20][20]={};
	int age[20]={};
	for(i=0;i<10;i++)
	{
		printf("Enter name and age of person %d : ",i+1);
		scanf("%s %d",name[i],&age[i]);
	}
	printf("Filter the age from :");
	scanf("%d",&amin);
	printf("Filter the age to :");
	scanf("%d",&amax);
	for(i=0;i<10;i++)
	{
		if(age[i]>=amin && age[i]<=amax) 
			printf("%s %d\n",name[i],age[i]);
	}
	return 0;
}