#include<stdio.h>

int main()
{
    int i,j,t,c,k,n,m,dat[1000][305]={};
    scanf("%d %d %d",&k,&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           scanf("%d",&t);
           dat[i][t]=t;
        }
    }
    scanf("%d",&c);
    for(i=0;i<n;i++)
    {
        if(dat[i][c]==0) {printf("%d",i+1); return 0;}
    }
    return 0;
}
