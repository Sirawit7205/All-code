#include<stdio.h>
#include<math.h>

int dat;

int replace(int data)
{
    int x=data%10;
    if(x==6) x=9;
    else if(x==9) x=6;
    if(data>10)
    {
        x=x+10*replace(data/10);
    }
    return x;
}

int main()
{
    scanf("%d",&dat);
    printf("%d",replace(dat));
    return 0;
}
