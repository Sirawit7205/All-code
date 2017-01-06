#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int dat[105][10005]={},ans=999999999;

int main()
{
    int n,m,i,j,iso=0,l,r,tem;
    char t;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        iso=0;
        for(j=1;j<=m;j++) {scanf(" %c",&t); if(t=='1') {iso=1; dat[i][0]++; dat[i][dat[i][0]]=j;}}
        if(iso==0) {printf("-1"); return 0;}
    }
    for(i=1;i<=m;i++)
    {
        tem=0;
        for(j=1;j<=n;j++)
        {
            l=lower_bound(dat[j]+1,dat[j]+dat[j][0],i)-dat[j];
            if(l==1) r=dat[j][0];
            else if(l==dat[j][0]+1) {l=dat[j][0]; r=1;}
            else r=l-1;
            l=min(abs(i-dat[j][l]),abs(i-dat[j][l]+m));
            r=min(abs(i-dat[j][r]),abs(i-dat[j][r]+m));
            tem+=min(l,r);
        }
        ans=min(ans,tem);
    }
    printf("%d",ans);
    return 0;
}
