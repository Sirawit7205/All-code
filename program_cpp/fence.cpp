#include<iostream>
#include<cstdio>

using namespace std;

int mode=0;

int main()
{
    start:;
    int i,j,k,n,m,t,ta,tb,a[505][505]={};
    scanf("%d %d",&n,&m);
    scanf("%d",&t);
    for(i=0;i<t;i++) {scanf("%d %d",&ta,&tb); a[ta+1][tb+1]=1;}
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) a[i][j]+=(a[i-1][j]+a[i][j-1])-a[i-1][j-1];
    }
    for(i=min(n,m);i>=1;i--)
    {
        for(j=1;j<=(n-i)+1;j++)
        {
            for(k=1;k<=(m-i)+1;k++)
            {
                ta=(i+j)-1; tb=(i+k)-1;
                if(a[ta][tb]-a[ta][tb-i]-a[ta-i][tb]+a[ta-i][tb-i]==a[ta-1][tb-1]-a[ta-1][tb-1-(i-2)]-a[ta-1-(i-2)][tb-1]+a[ta-1-(i-2)][tb-1-(i-2)]) {printf("%d\n",i); if(mode==0) {mode=1; goto start;} else return 0;}
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) printf("%d ",a[i][j]);
        printf("\n");
    }*/
    return 0;
}
