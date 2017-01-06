#include<cstdio>
#include<climits>

int qsl[2005][2005]={},qsr[2005][2005]={},qs[2005][2005]={},d[2005][2005]={},mx=INT_MIN;

int main()
{
    int i,j,n,m,k,c=1,x,y,t=1;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) {scanf("%d",&d[i][j]); qs[i][j]+=qs[i][j-1]+d[i][j];}
    }
    x=n;
    while(1)
    {
        if(x==0) break;
        for(i=1;i<=c;i++)
        {
            if(x-i+1<1) break;
            qsl[x-i+1][c-i+1]=d[x-i+1][c-i+1]+qsl[x-i+2][c-i+1]+qsl[x-i+2][c-i+2]-qsl[x-i+3][c-i+2];
            if(i==k) if(qsl[x-i+1][c-i+1]>mx) mx=qsl[x-i+1][c-i+1];
            if(i==k&&x-i+1+k==n) {qsl[x-i+1][c-i+1]-=qs[n][c-i+1+k]-qs[n][c-i];}
        }
        if(c<m) c++; else x--;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) {printf("%d ",qsl[i][j]);} printf("\n");
    }
    printf("%d",mx);
    return 0;
}
