#include<stdio.h>

int main()
{
    int i,j,q,x,y,a,r;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&x,&y);
        a=(x*y)+1;
        for(r=1;r<=x;r++)
        {
            for(i=1;i<=x;i+=r)
            {
                for(j=2;j<=y;j++)
                a+=y-j+1;
            }
        }
        for(i=1;i<=y;i++)
            {
                for(j=2;j<=x;j++)
                a+=x-j+1;
            }
        printf("%d\n",a-1);
    }
    return 0;
}
