#include<cstdio>

long long int dat[200005]={},lim=-1,mx=0;

int main()
{
    long long int n,i,j,cnt;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {scanf("%lld",&dat[i]); if(dat[i]>lim) lim=dat[i];}
    for(i=1;i<=lim;i++)
    {
        cnt=0;
        for(j=0;j<n;j++) {if(dat[j]%i==0) cnt++;}
        if(cnt<2) continue;
        else {if(cnt*i>mx) mx=cnt*i;}
    }
    printf("%lld",mx);
    return 0;
}
