#include<iostream>
#include<cstdio>

using namespace std;

int chk[10]={};

int main()
{
    int i,n,m,j,l;
    scanf("%d %d",&n,&m);
    chk[0]=1;
    for(i=1;i<=6;i++) {chk[i]=chk[i-1]*2;}
    for(i=0;i<n;i++)
    {
        scanf("%d",&l);
        printf("Yes");
    }
    return 0;
}
