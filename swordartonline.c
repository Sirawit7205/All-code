#include<stdio.h>

int main()
{
    int h,m,gm;
    scanf("%d %d",&h,&m);
    gm=m-45;
    if(gm<0)
    {
        gm+=60;
        if(h==0)
        {h=23;}
        else
        {h--;}
    }
    printf("%d %d",h,gm);
    return 0;
}
