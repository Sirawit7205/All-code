#include<stdio.h>

int main()
{
    int i,h,m,d=45;
    scanf("%d %d",&h,&m);
    if(m>=45)
    {
        printf("%d %d",h,m-45);
        return 0;
    }
    else
    {
        d-=m;
        if(h!=0)
        {
            printf("%d %d",h-1,60-d);
            return 0;
        }
        else
        {
            printf("23 %d",60-d);
            return 0;
        }
    }
}
