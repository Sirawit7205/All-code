#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {return (*(int*)a-*(int *)b);}

int a[300005]={},b[300005]={};

int main()
{
    int i,j,n,q,cp;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
    qsort(a,n,sizeof(int),cmp);
    qsort(b,n,sizeof(int),cmp);
    for(i=0;i<q;i++)
    {
        scanf("%d",&cp);
        printf("%d\n",a[cp-1]+b[cp-1]);
    }
    return 0;
}
