#include<stdio.h>

float cal(float num,float rate)
{
    num+=(num*rate)/100;
    return num;
}

int main()
{
    int i,y;
    float num,rate;
    printf("Number of people: "); scanf("%f",&num);
    printf("Increase rate: "); scanf("%f",&rate);
    printf("Number of year: "); scanf("%d",&y);
    for(i=1;i<=y;i++)
    {
        num=cal(num,rate);
        printf("Year %d -> %.2f\n",i,num);
    }
    return 0;
}
