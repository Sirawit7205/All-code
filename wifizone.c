#include<stdio.h>

int dat[10001][4]={};

int main()
{
    int n,m,x,y,k,q,i,j,cnt=0,ta,tb;
    scanf("%d %d %d %d",&n,&m,&k,&q);
    for(i=0;i<k;i++) scanf("%d %d %d",&dat[i][0],&dat[i][1],&dat[i][2]);
    for(i=0;i<q;i++)
    {
        cnt=0;
        scanf("%d %d",&ta,&tb);
        for(j=0;j<k;j++)
        {
            n=dat[j][0]-(dat[j][2]/2); m=dat[j][0]+(dat[j][2]/2); x=dat[j][1]-(dat[j][2]/2); y=dat[j][1]+(dat[j][2]/2);
            if(ta>=n&&ta<=m&&tb>=x&&tb<=y) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
