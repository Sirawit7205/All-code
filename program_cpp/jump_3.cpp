#include<iostream>
#include<cstdio>

using namespace std;

int dat[100001]={},ma[100001]={};

int main()
{
    int i,c;
    scanf("%d",&c);
    for(i=0;i<c;i++) scanf("%d",&dat[i]);
    ma[2]=dat[2];
    for(i=3;i<c;i++)
    {
        if(ma[i-1]>=ma[i-3]+dat[i]) ma[i]=ma[i-1]; else ma[i]=ma[i-3]+dat[i];
    }
    printf("%d",ma[c-1]);
    return 0;
}
