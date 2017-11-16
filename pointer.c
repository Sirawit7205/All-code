#include<stdio.h>

void number(int *x,int y,int *z)
{
	printf("FUNC: %d %d %d\n",*x,y,*z);
	(*x)+=5;
	y+=10;
	(*z)+=15;
	printf("FUNC: %d %d %d\n",*x,y,*z);
}

int main()
{
	int x=5,y=6,z=7;
	printf("%d %d %d\n",x,y,z);
	number(&x,y,&z);
	printf("%d %d %d\n",x,y,z);
	number(&y,z,&x);
	printf("%d %d %d\n",x,y,z);
	return 0;
}