#include<stdio.h>

int dat[1002][1002]={},rsum[1002]={},csum[1002]={};

int main()
{
    int i,j,n,m,q,t=0;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&dat[i][j]); csum[j]+=dat[i][j]; t+=dat[i][j];
        }
        rsum[i]=t;
        t=0;
    }
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",rsum[n]+csum[m]-dat[n][m]);
    }
    /*for(i=1;i<=n;i++) printf("%d ",rsum[i]);
    printf("\n");
    for(i=1;i<=m;i++) printf("%d ",csum[i]);*/
    return 0;
}
