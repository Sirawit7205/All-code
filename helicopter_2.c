#include<stdio.h>

int main()
{
    int i,a,b,x,d=0;
    scanf("%d %d",&a,&b);
    a--; b--;
    if(a==1&&b==1) printf("1");
    else if(a==1) printf("%d",b+1);
    else if(b==1) printf("%d",a+1);
    else if(a==b) printf("%d",a);
    else
    {
        if(b>a) x=a; else x=b;
        //for(i=1;i<x;i++) d+=i;
        printf("%d",2*x);
    }
    return 0;
}
