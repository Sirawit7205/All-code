#include<stdio.h>

int main()
{
    int a,c,i,j;
    float b,ans[15];
    for(i=0;i<14;i++)
    {
        scanf("%d %f %d",&a,&b,&c);
        for(j=0;j<(c/a);j++)
        {
            b=b/2;
        }
        ans[i]=b;
    }
    for(i=0;i<14;i++)
    {
        printf("%.2f\n",ans[i]);
    }
    return 0;
}
