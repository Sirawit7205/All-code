#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,dat[1001][2]={},b[1001][1001]={},w[1001]={};

int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {scanf("%d %d",&dat[i][0],&dat[i][1]);}
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(dat[i][0]<=j)
            {
                b[i][j]=max(b[i-1][j],b[i-1][j-dat[i][0]]+dat[i][1]);
            }
            else b[i][j]=b[i-1][j];
        }
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",b[n][m]);
    return 0;
}
