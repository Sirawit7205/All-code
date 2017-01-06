#include<cstdio>
#include<climits>

int s[255][255]={},n,ans=INT_MIN;

int main()
{
    int i,j,k,l,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) {scanf("%d",&s[i][j]); s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];}
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=n;k>=i;k--)
            {
                for(l=n;l>=j;l--) {t=s[k][l]-s[k-i][l]-s[k][l-j]+s[k-i][l-j]; if(t>ans) ans=t;}
            }
        }
    }
    printf("%d",ans);
    return 0;
}
