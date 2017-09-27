#include<stdio.h>
#include<math.h>

int quadratic(double a,double b,double c,double *x1,double *x2)
{
	int check;
	if(a==0||((b*b)-(4*a*c))<0)
		check=0;
	else if((b*b)-(4*a*c)==0)
		check=1;
	else
		check=2;
	(*x1)=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
	(*x2)=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
	return check;
}

int main()
{
	double a=0,b=5,c=4,x1,x2;
	int check;
	check=quadratic(a,b,c,&x1,&x2);
	if(check==0)
		printf("Error\n");
	else if(check==1)
		printf("1 answer: %.6lf (DBG %.6lf)\n",x1,x2);
	else
		printf("2 answers: %.6lf and %.6lf\n",x1,x2);
	return 0;
}
