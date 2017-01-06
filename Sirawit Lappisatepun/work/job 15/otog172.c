#include<stdio.h>

int dat[16][17]={},max=0,n,m;

int recur(int x,int y,int cur)
{
    int t=dat[x][y];
    if(x<1||y<1||x>n||y>m) {return;}
    else
    {
        cur+=dat[x][y];
        if(cur>max) max=cur;
        recur(x+1,y,cur);
        recur(x,y+1,cur);
    }
}

int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) scanf("%d",&dat[i][j]);
    }
    recur(1,1,0);
    printf("%d",max);
    return 0;
}
