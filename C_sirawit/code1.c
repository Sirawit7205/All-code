#include<stdio.h>

void test_for_control (int x, int y)
{
	int a,b,c,d,e=0,f=0;
	for(a=1,c=1;c<=y;a++)
	{
		b=a+x;
		c=c+b;
		d=c-b;
		if(c%2==1)
			e=c+d;
		else
			f=c-d;
		printf("%8d %8d %8d %8d %8d %8d\n",a,b,c,d,e,f);
	}
}

int main()
{
	test_for_control(1,40);
	return 0;
}
