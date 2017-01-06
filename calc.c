#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	double a,b,c,d;
	int e;
	char x[20],y[20];
	scanf("%lf %lf %lf",&a,&b,&c);
	d=a+b;
	sprintf(x,"%.10lf",c); sprintf(y,"%.10lf",d);
	e=strcmp(x,y);
	if(e==0) printf("Correct");
	else printf("Wrong");
	return 0;
}