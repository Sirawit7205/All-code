#include<stdio.h>

int main()
{
	double dx,dy=1.0,min,max,m,c,ch,x,y;
	
	while(1)
	{
		printf("Enter y=min and y=max: ");
		scanf("%lf %lf",&min,&max);
		
		dx=max-min;
		m=dy/dx;
		
		printf("Enter y=1 point: ");
		scanf("%lf",&ch);
		
		c=1-(m*ch);
		
		printf("Equation> y=%gx+(%g)\n",m,c);
		
		printf("Enter check point: ");
		scanf("%lf",&x);
		
		y=(m*x)+c;
		printf("Answer: %g\n\n",y);		
	}
	return 0;
}