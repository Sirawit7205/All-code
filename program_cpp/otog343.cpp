#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int n,m,d[100005]={},dp[100005][2]={};

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(j=1;j<=m;j++) scanf("%d",&d[j]);
        for(j=2;j<=m;j++)
        {
            dp[j][0]=max(abs(1-d[j-1])+dp[j-1][1],abs(1-1)+dp[j-1][0]);
            dp[j][1]=max(abs(d[j]-1)+dp[j-1][0],abs(d[j]-d[j-1])+dp[j-1][1]);
        }
        printf("%d\n",max(dp[m][0],dp[m][1]));
    }
    return 0;
}
