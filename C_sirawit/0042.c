#include<stdio.h>

int main()
{
    int i, j, q, tar;
    long double ans;

    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&tar);
        ans=1;
        for(j=0;j<tar;j++)
            ans*=2;
        printf("%.0Lf\n",ans);
    }
    return 0;
}
