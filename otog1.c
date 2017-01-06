#include<stdio.h>

int main()
{   int tmp,i,j,n,q,ans[1001]={},pos[100001]={};
    long min,max;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        pos[i]=tmp;
    }
    for(i=0;i<q;i++)
    {
        scanf("%ld %ld",&min,&max);
        for(j=0;j<n;j++)
        {if(pos[j]>=min&&pos[j]<=max) ans[i]++;}
    }
    for(i=0;i<q;i++)
    {printf("%d\n",ans[i]);}
    return 0;
}
