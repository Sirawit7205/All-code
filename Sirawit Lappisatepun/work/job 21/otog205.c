#include<stdio.h>

int dat[1000][1002]={};

int main()
{
    int x,y,n,m,i,j,sum=0;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) scanf("%d",&dat[i][j]);
    }
    for(i=0;i<n;i++) sum+=dat[i][y-1];
    for(i=0;i<m;i++) sum+=dat[x-1][i];
    sum-=dat[x-1][y-1];
    printf("%d",sum);
    return 0;
}
