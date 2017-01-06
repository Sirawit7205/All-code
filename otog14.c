#include<stdio.h>

int ans[25][3]={};

int main()
{
    int i,b=1,c=0,tb,tc;
    for(i=1;i<=24;i++)
    {
        tb=0; tc=0;
        tb=1+c+b; tc=b;
        b=tb; c=tc; ans[i][0]=b; ans[i][1]=b+c+1;
    }
    while(1)
    {
        scanf("%d",&tc);
        if(tc==-1) break;
        else printf("%d %d\n",ans[tc][0],ans[tc][1]);
    }
    return 0;
}
