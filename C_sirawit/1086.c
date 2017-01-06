#include<stdio.h>

int main()
{
    int i,j,n,k,a,dat[102]={},cnt=0,ans1=0,ans2=0;
    scanf("%d %d %d",&n,&k,&a);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&dat[i]);
        if(i!=1) dat[i]+=dat[i-1];
        /*if(i!=1) dat[i]=dat[i-1]+cnt;
        scanf("%d",&cnt);*/
    }
    for(i=1;i<=dat[n];i++)
    {
        if((i+(k*a)-1)>dat[n]) break;
        for(j=i;j<i+(k*a)+1;j+=a)
        {
            if()
        }
        if(cnt>ans1) {ans1=cnt; ans2=i;}
        cnt=0;
    }
    printf("%d %d",ans2,ans1);
    return 0;
}
