#include<stdio.h>

int main()
{
    int a,b,t,i;
    scanf("%d %d",&a,&b);
    if(b>a) {t=a; a=b; b=t;}
    for(i=a;i>=1;i--)
    {
        if(a%i==0&&b%i==0) {printf("%d",i); return 0;}
    }
}
