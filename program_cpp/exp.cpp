#include<iostream>
#include<cstdio>

using namespace std;

int m,n,sa[1005]={},sb[1005]={};

int chk(int a,int b,int t)
{
    if(t>m||a==0||b==0) return 0;
    return(max(chk(a-1,b-1,t),t+sa[a]));
}

int main()
{
    int i,a;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++) scanf("%d",&sa[i]);
    for(i=0;i<n;i++) scanf("%d",&sb[i]);
    a=chk(n-1,n-1,0);
    printf("%d",a);
    return 0;
}
