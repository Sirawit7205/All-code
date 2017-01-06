#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    int *aa=(int *)a;
    int *bb=(int *)b;
    return *aa-*bb;
}

int cmpb(const void *a,const void *b)
{
    int *aa=(int *)a;
    int *bb=(int *)b;
    return *bb-*aa;
}

int main()
{
    int n,i,t,max=0,data[100001]={},datb[100001]={};
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&data[i]);
    for(i=0;i<n;i++) scanf("%d",&datb[i]);
    qsort(data,n,sizeof(int),cmp);
    qsort(datb,n,sizeof(int),cmpb);
    for(i=0;i<n;i++)
    {
        if(data[i]<datb[i]) t=data[i];
        else t=datb[i];
        if(t>max) max=t;
    }
    printf("%d",max);
    //for(i=0;i<n;i++) printf("%d ",data[i]);
    //for(i=0;i<n;i++) printf("%d ",datb[i]);
    return 0;
}
