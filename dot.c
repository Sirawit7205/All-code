#include<stdio.h>

int f[1005][1005]={};

int main()
{
    int i,n,c=0,ta,tb;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&ta,&tb);
        if(f[ta][tb]==0) {c++; f[ta][tb]=1;}
    }
    printf("%d",c);
    return 0;
}
