#include<cstdio>
#include<algorithm>

int k,n,d[7000005]={},p[7000005]={},mts=0;

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&d[i]);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(mts+d[i]<0) {p[i]=d[i]; mts=0;}
        else {mts+=d[i]; p[i]=mts;}
    }
    //for(i=0;i<n;i++) printf("%d ",p[i]);
    std::nth_element(p,p+k,p+n);
    printf("%d",p[k]);
    return 0;
}
