#include<stdio.h>

int a[3500005]={},b[3500005]={};

int main()
{
    int i,j,n,q,t,c=0,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++) {scanf("%d",&t); a[t]++;}
    for(i=0;i<=n;i++)
    {
        if(a[i]==0) continue;
        for(j=0;j<a[i];j++) {b[c]=i; c++;}
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",b[x-1]-b[y-1]);
    }
    return 0;
}
