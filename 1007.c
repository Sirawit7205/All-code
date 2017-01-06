#include<stdio.h>

int main()
{
    int i,j;
    long long int cntt[25][3]={},cnta=1,cntb=0,t;
    for(i=1;i<=24;i++)
    {
        t=cnta;
        cnta=cnta+cntb+1;
        cntb=t;
        cntt[i][0]=cnta+cntb+1;
        cntt[i][1]=cnta;
    }
    while(1)
    {
        scanf("%d",&j);
        if(j==-1) break;
        else printf("%lld %lld\n",cntt[j][1],cntt[j][0]);
    }
    return 0;
}
