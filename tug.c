#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp (const void *a, const void *b) {return (*(int*)a-*(int*)b);}

int main()
{
    int amt,i,a[2005]={},b[2005]={};
    long long int total=0;
    scanf("%d",&amt);
    for(i=0;i<amt;i++) scanf("%d",&a[i]);
    for(i=0;i<amt;i++) scanf("%d",&b[i]);
    qsort(a,amt,sizeof(int),cmp);
    qsort(b,amt,sizeof(int),cmp);
    for(i=0;i<amt;i++) total+=abs(a[i]-b[i]);
    printf("%lld",total);
    return 0;
}
