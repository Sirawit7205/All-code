#include<iostream>
#include<cstdio>

using namespace std;

int power(int n,int m)
{
    int i,a=1;
    for(i=0;i<m;i++) a*=n;
    return a;
}

int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    if(m<(power(2,n)-1)/2) chk(n,m,0);
    else if(m==((power(2,n)-1)/2)
    return 0;
}
