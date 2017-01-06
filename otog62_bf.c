#include<stdio.h>

int main()
{
    int i,j,n,ans=0,m,t,x;
    scanf("%d",&n);
    for(i=1;i<=1000000000;i++)
    {
        x=i; m=1000000000; t=0;
        for(j=1;j<=10;j++) {t+=x/m; x%=m; m/=10;}
        if(t==n) {ans++;}
    }
    printf("%d",ans);
    return 0;
}
