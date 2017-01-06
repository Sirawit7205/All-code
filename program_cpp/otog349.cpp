#include<cstdio>
#include<algorithm>

using namespace std;

long long int qsum[100005]={},dp[100005]={},dat[100005]={};

int main()
{
    long long int i,j,n,m,x,y,z;
    scanf("%lld",&m);
    for(i=0;i<m;i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++) scanf("%lld",&dat[j]);
        qsum[n]=0;
        for(j=n-1;j>=0;j--) qsum[j]=qsum[j+1]+dat[j];
        for(j=n-1;j>=0;j--)
        {
            if(j+1<=n-1) x=dp[j+1]; else x=0;
            if(j+2<=n-1) y=dp[j+2]; else y=0;
            if(j+3<=n-1) z=dp[j+3]; else z=0;
            dp[j]=qsum[j]-min(x,min(y,z));
        }
        printf("%lld\n",dp[0]);
    }
    return 0;
}
