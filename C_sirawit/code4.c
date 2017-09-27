#include<stdio.h>

int fibonacci(int n)
{
	int i,a=0,b=1,c;
	if(n==0)
		return 0;
	for(i=0;i<n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return a;
}

int summodfibo(int n)
{
	int sum=0,i,count,returnVal;
	for(i=0,count=0;count<n;i++)
	{
		returnVal=fibonacci(i);
		if(returnVal%2==1)
		{
			count++;
			sum+=returnVal;
		}
	}
	return sum;
}

int main()
{
	int n=5;
	printf("%d: %d\n",n,summodfibo(n));
	return 0;
}
