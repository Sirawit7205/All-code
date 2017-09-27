#include<stdio.h>
#include<math.h>

int main()
{ double z,r,A,B,C;
	printf("Enter magnitude of vector A : ");
	scanf("%lf",&A);
	printf("Enter magnitude of vector B : ");
	scanf("%lf",&B);
	printf("Enter angle in degree unit : ");
	scanf("%lf",&z);
	r=(z*M_PI)/180;
	C=sqrt((A*A)+(B*B)-(2*A*B*cos(r)));
	printf("Answer magnitude of vector C = %.6lf\n",C);
	return 0;
}

