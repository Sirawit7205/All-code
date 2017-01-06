#include<iostream>
#include<cstdio>

using namespace std;

int dat[10005]={};

int main()
{
    int i,j,k,m,ta,tb,c[5]={};
    char t;
    scanf("%d %d",&m,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&ta,&tb);
        for(j=ta;j<=tb;j++) dat[j]++;
    }
    for(i=1;i<=m;i++) c[dat[i]%3]++;
    scanf(" %c",&t);
    scanf(" %c",&mode);
    if(mode=='R') printf("%d",c[0]);
    else if(mode=='G') printf("%d",c[1]);
    else printf("%d",c[2]);
    return 0;
}
