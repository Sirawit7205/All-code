#include<stdio.h>

void INT(int i)
{
    if(i>100) return;
    printf("% 5d",i);
    if(i%10==0) printf("\n");
    INT(i+1);
}

int main()
{
    INT(1);
    return 0;
}
