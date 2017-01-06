#include<stdio.h>

FiMul(int a)
{
    if(a==1) return 7;
    else if(a==2||a==3) return -2;
    else return ((FiMul(a-2)*3)+(FiMul(a-3)*4));
}

int main()
{
    int dat;
    scanf("%d",&dat);
    printf("%d",FiMul(dat));
    return 0;
}
