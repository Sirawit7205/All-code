#include<stdio.h>

int dword[1002][1002]={};

int main()
{
    int m,n,k,i,j,t,max=0;
    scanf("%d %d",&m,&n);
    scanf("%d",&k);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&t);
            dword[i][j]=t+dword[i-1][j]+dword[i][j-1]-dword[i-1][j-1];
        }
    }
    for(i=k;i<=m;i++)
    {
        for(j=k;j<=n;j++)
        {
            t=dword[i][j]-dword[i-k][j]-dword[i][j-k]+dword[i-k][j-k];
            if(t>max) max=t;
        }
    }
    printf("%d",max);
    return 0;
}
