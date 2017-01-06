#include<stdio.h>
#include<math.h>

int main()
{
    double ans1,ans2;
    int a;
    scanf("%d",&a);
    ans1=M_PI*pow(a,2);
    ans2=2*pow(a,2);
    printf("%.6f\n%.6f",ans1,ans2);
    return 0;
}
