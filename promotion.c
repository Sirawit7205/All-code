#include<stdio.h>

int dat[205][205]={},tmp[200]={},prt[200]={};

int main()
{
    int i,j,n,t,k;
    scanf("%d",&n);
    for(i=0;i<(n*(n-1))/2;i++)
    {
        scanf("%d",&t);
        for(j=1;j<=t;j++) scanf("%d",&tmp[j]);
        if(n!=2)
        {
            for(j=1;j<=t;j++)
            {
                dat[tmp[j]][0]++;
                for(k=1;k<=t;k++)
                {
                    if(k==j) continue;
                    dat[tmp[j]][tmp[k]]++;
                }
            }
        }
        else
        {
            printf("1 %d\n%d ",tmp[1],t-1);
            for(i=2;i<=t;i++) printf("%d ",tmp[i]);
        }
    }
    for(j=1;j<=200;j++)
    {
        if(prt[j]==1||dat[j][0]==0) continue;
        t=1; tmp[0]=0;
        for(k=1;k<=200;k++)
        {
            if(dat[j][k]==dat[j][0]) {tmp[0]++; tmp[t]=k; prt[k]=1; t++;}
        }
        prt[j]=1;
        printf("%d %d ",tmp[0]+1,j);
        for(i=1;i<=tmp[0];i++) printf("%d ",tmp[i]);
        printf("\n");
    }
    return 0;
}
