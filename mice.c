#include<stdio.h>

int cal(int n)
{
    if(n<0) return 0;
    if(n<3) return 1;
    return cal(n-1)+cal(n-15)*4;

}

int main()
{
    int n;
    scanf("%d",&n);
    n=cal(n);
    printf("%d",n*2);
    return 0;
}
