#include<cstdio>

int a[100005]={},b[100005]={},ca[100005]={},cb[100005]={},ta=0,tb=0;

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++) scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        if(cb[a[i]]!=0) {cb[a[i]]--; tb--;} else {ca[a[i]]++; ta++;}
        if(ca[b[i]]!=0) {ca[b[i]]--; ta--;} else {cb[b[i]]++; tb++;}
        if(ta==0&&tb==0) break;
    }
    printf("%d",i);
    return 0;
}
