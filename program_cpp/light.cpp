#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int d[50005][2]={},l[100005]={};

int main()
{
    int i,n,m;
    long long ba,bb,total=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d %d",&d[i][0],&d[i][1]);
    for(i=1;i<=m;i++) scanf("%d",&l[i]);
    sort(l,l+m+1);
    l[m+2]=500000001;
    for(i=1;i<=n;i++)
    {
        ba=upper_bound(l,l+m+1,d[i][0])-l;
        bb=lower_bound(l,l+m+1,d[i][1])-l;
        //if(l[bb]==d[i][1]) total+=(bb-ba-1)%2007;
        //if(l[ba]==d[i][0]&&l[bb]==d[i][1]) total+=((bb-ba)-1)%2007;
        total+=(bb-ba)%2007;
    }
    printf("%lld",total%2007);
    return 0;
}
