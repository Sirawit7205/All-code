#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int num[3500005]={};

/*int cmp(const void *a,const void *b)
{
    int *aa=(int *)a;
    int *bb=(int *)b;
    return *aa-*bb;
}*/

int main()
{
    int i,n,q,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    //qsort(num,n,sizeof(int),cmp);
    sort(num,num+n);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",num[a-1]-num[b-1]);
    }
    return 0;
}
