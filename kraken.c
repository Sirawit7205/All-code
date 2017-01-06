#include<stdio.h>

int f[1002][1002]={};

int main()
{
    int m,n,k,l,i,j,t,max=0;
    scanf("%d %d",&m,&n);
    scanf("%d",&k);
    for(i=0;i<m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&t);
            f[i][j]=f[i][j-1]+t;
        }
    }
    for(i=0;i<(m-k)+1;i++)
    {
        for(j=0;j<(n-k)+1;j++)
        {
            for(l=0;l<k;l++)
            {t+=f[i+l][j+k]-f[i+l][j];}
            if(t>max) max=t;
            t=0;
        }
    }
    printf("%d",max);
    return 0;
}
