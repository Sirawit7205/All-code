#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a+b==c) printf("1");
    else if((a*a)+(b*b)==(c*c)) printf("2");
    else printf("NO");
    return 0;
}
