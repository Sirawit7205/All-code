#include<stdio.h>

int seta[1000005]={},setb[1000005]={};

int main()
{
    int i,n,t,ti,max=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        seta[t]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(seta[t]==0) continue;
        else
        {
            if(seta[t]==i) ti=0;
            else if(seta[t]>i) ti=n-(seta[t]-i);
            else ti=i-seta[t];
        }
        setb[ti]++;
    }
    for(i=0;i<n;i++) if(setb[i]>max) {max=setb[i]; ans=i;}
    printf("%d %d",max,ans);
    //printf("seta setb\n");
    //for(i=1;i<=n;i++) printf("%d %d\n",seta[i],setb[i]);
    return 0;
}
