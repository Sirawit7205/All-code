#include<stdio.h>

int arr[10]={6,2,8,4,3,7,5,1};
int t[10]={};

void merge(int l, int m, int r)
{
    int k=l,i=l,j=m+1;
    while(i<=m&&j<=r)
    {
        if(i==m+1) {t[k]=arr[j]; j++;}
        else if(j==r+1) {t[k]=arr[i]; i++;}
        if(arr[i]>arr[j]) {t[k]=arr[j]; j++;}
        else {t[k]=arr[i]; i++;}
        k++;
    }
    while(i<=m) {t[k]=arr[i]; i++; k++;}
    while(j<=r) {t[k]=arr[j]; j++; k++;}
    for(i=l;i<=r;i++) arr[i]=t[i];
    return;
}

void sep(int l, int r)
{
    int m;
    if(l==r) return;
    m=(l+r)/2;
    sep(l,m);
    sep(m+1,r);
    merge(l,m,r);
}

int main()
{
    int i;
    sep(0,7);
    for(i=0;i<8;i++) printf("%d ",arr[i]);
    return 0;
}
