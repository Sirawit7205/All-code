#include<iostream>
#include<cstdio>

using namespace std;

int h[1005][1005]={},c[1005][1005]={};

int main()
{
    int m,n,i,j,ma=0,a=0;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++) scanf("%d",&h[i][j]);
    }
    for(i=1;i<=n;i++) c[1][i]=1;
    for(i=2;i<=m;i++)
    {
        if(i%2==0)
        {
            for(j=1;j<n;j++)
            {
                if(h[i-1][j]==h[i-1][j+1]) {h[i][j]+=h[i-1][j]; c[i][j]=c[i-1][j]+c[i-1][j+1];}
                else {h[i][j]+=max(h[i-1][j],h[i-1][j+1]); if(h[i-1][j]>h[i-1][j+1]) c[i][j]=c[i-1][j]; else c[i][j]=c[i-1][j+1];}
            }
            h[i][j]+=h[i-1][j]; c[i][j]=c[i-1][j];
        }
        else
        {
            for(j=2;j<=n;j++)
            {
                if(h[i-1][j-1]==h[i-1][j]) {h[i][j]+=h[i-1][j]; c[i][j]=c[i-1][j-1]+c[i-1][j];}
                else {h[i][j]+=max(h[i-1][j-1],h[i-1][j]); if(h[i-1][j-1]>h[i-1][j]) c[i][j]=c[i-1][j-1]; else c[i][j]=c[i-1][j];}
            }
            h[i][1]+=h[i-1][1]; c[i][1]=c[i-1][1];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(h[m][i]>ma) {ma=h[m][i]; a=c[m][i];}
        else if(h[m][i]==ma) a+=c[m][i];
    }
    printf("%d %d",ma,a);
    return 0;
}
