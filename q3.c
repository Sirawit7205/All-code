#include<stdio.h>
#include<stdlib.h>

struct dat{
 int x;
 int y;
 int d;
};

struct dat w[1001]={};

int cmp(const void *a, const void *b)
{
    struct dat *aa=(struct dat*)a;
    struct dat *bb=(struct dat*)b;
    if(aa->d > bb->d) return 1;
    else return -1;
}

int main()
{
    int i,j,n,a,b,min,max,mint=1000001,t=0;
    scanf("%d %d %d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&w[i].x,&w[i].y);
        w[i].d=w[i].x-w[i].y;
    }
    qsort(w,n,sizeof(w[0]),cmp);
    min=(n/2)+a+(n%2); max=n-b;
    for(i=min;i<=max;i++)
    {
        for(j=0;j<i;j++) t+=w[j].x;
        for(j=i;j<n;j++) t+=w[j].y;
        if(t<mint) mint=t;
        t=0;
    }
    printf("%d",mint);
    return 0;
}
