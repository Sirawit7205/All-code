#include<stdio.h>
int A(int *);
int main()
{
	int X[10];
	X[4]=0;
	printf("%d\n",X[4]);
	A(X);
	printf("%d",X[4]);
}
int A(int *Y)
{
	Y[4]=1;
}