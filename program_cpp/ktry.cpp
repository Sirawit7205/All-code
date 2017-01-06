#include<iostream>
#include<cstdio>

using namespace std;

int c[1000005][2]={},ans[1000005]={};

int main()
{
    int x,y,z,i,t,m=0,ma=0,cur=0;
    scanf("%d %d %d",&x,&y,&z);
    for(i=1;i<=y;i++) scanf("%d %d",&c[i][0],&c[i][1]);
    for(i=1;i<=z;i++)
    {
        scanf("%d",&t);
        ans[c[t][0]]+=1; ans[c[t][1]+1]+=-1;
    }
    for(i=1;i<=x;i++)
    {
        cur+=ans[i];
        if(cur>ma) {ma=cur; m=i;}
    }
    printf("%d %d",m,ma);
    return 0;
}
