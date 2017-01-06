#include<stdio.h>
#include<limits.h>

int cache[SHRT_MAX]={};

int chk(int n)
{
    int c;
    if(n<5&&n!=0) return 0;
    if(n==0||n%5==0||n%7==0||n%9==0||n%12==0||n%14==0||n%16==0) return 1;
    if(cache[n-5]!=0) return cache[n-5]; else {c=chk(n-5); cache[n-5]=c;}
    if(cache[n-7]!=0) return cache[n-7]; else {c=chk(n-7); cache[n-7]=c;}
    if(cache[n-9]!=0) return cache[n-9]; else {c=chk(n-9); cache[n-9]=c;}
    if(cache[n-12]!=0) return cache[n-12]; else {c=chk(n-12); cache[n-12]=c;}
    if(cache[n-14]!=0) return cache[n-14]; else {c=chk(n-14); cache[n-14]=c;}
    if(cache[n-16]!=0) return cache[n-16]; else {c=chk(n-16); cache[n-16]=c;}
}

int main()
{
    int i,a,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a=chk(i);
        if(a==1) printf("%d=>Yes\n",i);
        else printf("%d=>No\n",i);
    }
    return 0;
}
