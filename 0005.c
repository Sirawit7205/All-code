#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c;
    scanf("%lf %lf",&a,&b);
    a=pow(a,2); b=pow(b,2);
    c=sqrt((a+b));
    printf("%lf",c);
    return 0;
}
