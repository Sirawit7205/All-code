#include<stdio.h>
//#include<time.h>
int num[10001]={},ans[10001]={};

void divide(int a,int b)
{
    int mid=(a+b)/2;
    if(a==b)
    {return;}
    divide(a,mid);
    divide(mid+1,b);
    merge(a,b,mid);
}

void merge(int a,int b,int mid)
{
    int i,j,k,l;
    i=a; j=mid+1; k=a;
    while(i<=mid&&j<=b)
    {
        if(num[i]<num[j])
            {ans[k++]=num[i++];}
        else
            {ans[k++]=num[j++];}
    }
    while(i<=mid) ans[k++]=num[i++];
    while(j<=b) ans[k++]=num[j++];
    for(l=a;l<=b;l++)
    {num[l]=ans[l];}
}

int main()
{
    int i,t;
    for(i=0;i<10001;i++) scanf("%d",&num[i]);
    //t=clock();
    divide(0,10000);
    for(i=0;i<10001;i++) printf("%d ",ans[i]);
    //printf("%d->%d",t,clock());
    return 0;
}
