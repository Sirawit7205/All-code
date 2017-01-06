#include<stdio.h>

#define pi 3.14159
int cal(float r);
int pr(float ans);

int sc()
{
    float r;
    printf("Enter circle radius: "); scanf("%f",&r);
    cal(r);
    return 0;
}

int cal(float r)
{
    float ans;
    ans=pi*r*r;
    pr(ans);
    return 0;
}

int pr(float ans)
{
    printf("The area of circle= %.2f",ans);
    return 0;
}

int main()
{
    sc();
    return 0;
}
