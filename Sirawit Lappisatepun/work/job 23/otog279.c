#include<stdio.h>

int main()
{
    int h,r,c,m;
    scanf("%d %d",&h,&r);
    scanf("%d",&c);
    m=(h*60)+r+c;
    h=m/60; r=m%60;
    if(h==24) h=0;
    if(h>23) h-=24;
    if(h<10) printf("0");
    printf("%d ",h);
    if(r<10) printf("0");
    printf("%d",r);
    return 0;
}
