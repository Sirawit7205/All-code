#include<stdio.h>

int dat[305][305]={};

void chk(int x,int y)
{
    int sa,sb,i,j,k,l,err=0,d[20][20]={};
    char t;
    scanf("%d %d",&sa,&sb);
    for(i=0;i<sb;i++)
    {
        for(j=0;j<sa;j++)
        {
            scanf(" %c",&t);
            d[i][j]=t-64;
        }
    }
    for(i=0;i<=y-sb;i++)
    {
        for(j=0;j<=x-sa;j++)
        {
            err=0;
            for(k=0;k<sb;k++)
            {
                for(l=0;l<sa;l++)
                {
                    if(d[k][l]!=dat[k+i][l+j]) {err=1; break;}
                }
                if(err==1) break;
            }
            if(err==0) {printf("%d %d\n",1+j+(sa-1)/2,1+i+(sb-1)/2); return;}
        }
    }
}

int main()
{
    int x,y,i,j,q;
    char t;
    scanf("%d %d",&x,&y);
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            scanf(" %c",&t);
            dat[i][j]=t-64;
        }
    }
    scanf("%d",&q);
    for(i=0;i<q;i++) chk(x,y);
    return 0;
}
