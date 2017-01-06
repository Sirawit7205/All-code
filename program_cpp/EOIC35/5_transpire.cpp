#include<iostream>
#include<cstdio>

int main()
{
    int i,len,mult=3;
    long long int ans=1;
    char tmp[5]={};
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        mult=3;
        scanf("%s",tmp);
        if(tmp[0]==tmp[1]) mult-=1;
        if(tmp[0]==tmp[2]) mult-=1;
        if(tmp[1]==tmp[2]) mult-=1;
        if(mult==0) mult=1;
        ans*=mult;
    }
    printf("%lld",ans);
    return 0;
}
