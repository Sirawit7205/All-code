#include<stdio.h>
#include<stdlib.h>

int dat[100005]={};

int cmp(const void *a, const void *b) {return (*(int*)a-*(int*)b);}

int bs(int s, int e, int t)
{
    int ax;
    if(s<=e)
    {
        ax=(s+e)/2;
        if(dat[ax]==t) return dat[ax];
        else if(dat[ax]>t) if(dat[ax-1]<t) return dat[ax-1]; else return bs(s,ax-1,t);
        else return bs(ax+1,e,t);
    }
    return dat[e];
}

int main()
{
    int a,b,i,t;
    scanf("%d %d",&a,&b);
    for(i=0;i<a;i++) scanf("%d",&dat[i]);
    qsort(dat,a,sizeof(int),cmp);
    for(i=0;i<b;i++)
    {
        scanf("%d",&t);
        if(t<dat[0]) printf("-1\n");
        else
        {
            t=bs(0,a-1,t);
            printf("%d\n",t);
        }
    }
    return 0;
}
