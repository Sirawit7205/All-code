#include<stdio.h>
#include<limits.h>

int qsum[105][105]={};

int main()
{
    int i,j,k,l,n,t,m=INT_MIN;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) {scanf("%d",&t); qsum[i][j]=t+qsum[i-1][j]+qsum[i][j-1]-qsum[i-1][j-1];}
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=i;k<=n;k++)
            {
                for(l=j;l<=n;l++)
                    if(qsum[k][l]-qsum[k][l-j]-qsum[k-i][l]+qsum[k-i][l-j]>m) m=qsum[k][l]-qsum[k][l-j]-qsum[k-i][l]+qsum[k-i][l-j];
            }
        }
    }
    printf("%d",m);
    return 0;
}
