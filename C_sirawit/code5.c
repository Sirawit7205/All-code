#include<stdio.h>

double sum_upper(int n)
{
	double sum=0;
	int i;
	for(i=1;i<=n;i++)
	{
		sum+=(i*2)-1;
	}
	return sum;
}

double sum_lower(int n)
{
	double sum=0;
	int i;
	for(i=1;i<=n;i++)
	{
		sum+=i*2;
	}
	return sum;
}

double Double_Serie_Test(int n)
{
	double sum=0;
	int i;
	for(i=1;i<=n;i++)
	{
		sum+=(sum_upper(i)/sum_lower(i));
	}
	return sum;
}

int main()
{
	double n=3;
	printf("%.0lf: %.6lf\n",n,Double_Serie_Test(n));
	return 0;
}
