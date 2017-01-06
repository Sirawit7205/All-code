#include<stdio.h>

int dat[100005]={};

int main()
{
    int n,m,i,t,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&dat[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        t=dat[a]; dat[a]=dat[b]; dat[b]=t;
    }
    for(i=1;i<=n;i++) printf("%d ",dat[i]);
    return 0;
}
