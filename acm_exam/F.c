#include<stdio.h>

int main()
{
    int i,mon,ans[15][10]={};
    for(i=0;i<14;i++)
    {
        scanf("%d",&mon);
        ans[i][0]=mon/1000; mon=mon%1000;
        ans[i][1]=mon/500; mon=mon%500;
        ans[i][2]=mon/100; mon=mon%100;
        ans[i][3]=mon/50; mon=mon%50;
        ans[i][4]=mon/20; mon=mon%20;
        ans[i][5]=mon/10; mon=mon%10;
        ans[i][6]=mon/5; mon=mon%5;
        ans[i][7]=mon/2; mon=mon%2;
        ans[i][8]=mon/1; mon=mon%1;
    }
    for(i=0;i<14;i++)
    {
        printf("case_%d\n",i+1);
        if(ans[i][0]!=0)  printf("1000 %d\n",ans[i][0]);
        if(ans[i][1]!=0)  printf("500 %d\n",ans[i][1]);
        if(ans[i][2]!=0)  printf("100 %d\n",ans[i][2]);
        if(ans[i][3]!=0)  printf("50 %d\n",ans[i][3]);
        if(ans[i][4]!=0)  printf("20 %d\n",ans[i][4]);
        if(ans[i][5]!=0)  printf("10 %d\n",ans[i][5]);
        if(ans[i][6]!=0)  printf("5 %d\n",ans[i][6]);
        if(ans[i][7]!=0)  printf("2 %d\n",ans[i][7]);
        if(ans[i][8]!=0)  printf("1 %d\n",ans[i][8]);

    }
    return 0;
}
