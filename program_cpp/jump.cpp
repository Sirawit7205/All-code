#include<iostream>
#include<cstdio>

int dat[100001]={},n,ans=0;

void chk(int a)
{
    if(a>n-1) return;
    if(dat[a]==0) chk(a+1);
    else if(a==n-1&&dat[a]>=dat[a-1]) {ans+=dat[a]; chk(a+3);}
    else if(a+3<n&&dat[a+3]>dat[a+1]) {ans+=dat[a]; chk(a+3);}
    else if(dat[a]>=dat[a-1]&&dat[a]>=dat[a+1]) {ans+=dat[a]; chk(a+3);}
    else chk(a+1);
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&dat[i]);
    chk(2);
    printf("%d",ans);
    return 0;
}
