#include<stdio.h>

int cal(int use)
{
    int pay=0;
    if(use>1000) pay+=(use-1000)*5+400*6+300*8+300*9;
    else if(use>600) pay+=(use-600)*6+300*8+300*9;
    else if(use>300) pay+=(use-300)*8+300*9;
    else pay+=use*9;
    return pay;
}

int main()
{
    int num,use;
    printf("Enter customer number: "); scanf("%d",&num);
    printf("Watt use: "); scanf("%d",&use);
    printf("Electric value= %d",cal(use));
    return 0;
}
