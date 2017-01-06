#include<stdio.h>

int chk(int scr)
{
    printf("Your grade= ");
    if(scr>=90) printf("4");
    else if(scr>=80) printf("3");
    else if(scr>=70) printf("2");
    else if(scr>=50) printf("1");
    else printf("0");
    return 0;
}

int main()
{
    int scr;
    printf("enter score: "); scanf("%d",&scr);
    chk(scr);
    return 0;
}
