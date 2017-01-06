#include<stdio.h>

int cal(int a)
{
    int i,sum=0;
    for(i=0;i<a*2;i+=2)
    {
        printf("%d",i);
        if(i!=(a*2)-2)printf("+");
        sum+=i;
    }
    return sum;
}

int main()
{
    int a,b;
    printf("Enter n: "); scanf("%d",&a);
    b=cal(a);
    printf("=%d",b);
    return 0;
}
