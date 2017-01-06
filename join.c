#include<stdio.h>

int cnt[1000005]={};

int main()
{
    int i,n,ta,tb,cur=0,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&ta,&tb);
        cnt[ta]++; cnt[tb]--;
    }
    for(i=0;i<1000005;i++)
    {
        cur+=cnt[i];
        if(cur>max) max=cur;
    }
    printf("%d",max);
    return 0;
}
