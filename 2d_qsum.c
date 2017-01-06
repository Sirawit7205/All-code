#include<stdio.h>

int dat[1005][1005]={};

int main()
{
    int n,m,i,j,t,a,b,c,d;
    scanf("%d %d %d",&n,&m,&t);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
    {
        scanf("%d",&dat[i][j]);
        dat[i][j]+=dat[i-1][j]+dat[i][j-1]-dat[i-1][j-1];
    }
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("SUM=%d\n",dat[a][b]-dat[a-c][b]-dat[a][b-d]+dat[a-c][b-d]);
    }
    return 0;
}
