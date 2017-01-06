#include<stdio.h>

int dat[305][305]={},row[305][305]={},col[305][305]={};

void chk(int x,int y)
{
    int sa,sb,i,j,k,err=0,d[20][20]={},dr[20]={},dc[20]={};
    char t;
    scanf("%d %d",&sa,&sb);
    for(i=0;i<sb;i++)
    {
        for(j=0;j<sa;j++)
        {
            scanf(" %c",&t);
            d[i][j]=t-64;
            if(t=='A') {dr[i]++; dc[j]++;}
        }
    }
    for(i=0;i<=y-sb;i++)
    {
        for(j=0;j<=x-sa;j++)
        {
            err=0;
            for(k=j;k<j+sa;k++)
                if(dc[k-j]!=(col[k][i+sb-1]-col[k][i-1])) {err=1; break;}
            if(err==1) continue;
            for(k=i;k<i+sb;k++)
                if(dr[k-i]!=(row[k][j+sa-1]-row[k][j-1])) {err=1; break;}
            if(err==0) {printf(" %d %d\n",1+j+(sa-1)/2,1+i+(sb-1)/2); return;}
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
            if(t=='A') {col[j][i]++; row[i][j]++;}
            if(i!=0) col[j][i]+=col[j][i-1];
            if(j!=0) row[i][j]+=row[i][j-1];
        }
    }
    scanf("%d",&q);
    for(i=0;i<q;i++) chk(x,y);
    return 0;
}
