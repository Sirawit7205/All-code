#include<cstdio>
#include<cmath>
#include<algorithm>

int n,m,pr[1000005]={},pcnt=2,ans=0;

int main()
{
    int i,j,lim,c=0;
    scanf("%d %d",&n,&m);
    if(n>m) std::swap(n,m);
    pr[1]=2; pr[2]=3;
    for(i=5;i<=m;i+=2)
    {
        lim=sqrt(i); c=0;
        for(j=1;j<=pcnt;j++)
        {
            if(pr[j]>lim) break;
            else if(i%pr[j]==0) {c=1; break;}
        }
        if(c==0)
        {
            pcnt++; pr[pcnt]=i;
        }
    }
    for(i=1;i<=pcnt;i++) if(pr[i]>=n&&pr[i]<=m) ans++;
    printf("%d",ans);
    return 0;
}
