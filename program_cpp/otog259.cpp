#include<cstdio>
#include"count.h"

int m=0;

//int GetN() {return 10;}
//int GetK() {return 2;}
//int Ans(int a) {
//    int x;
//    m+=a;
//    printf("CURRENT: %d ",m);
//    scanf("%d",&x);
//    return x+m;}
//int Second() {printf("CURRENT: 0\n"); scanf("%d",&m); return m;}

int main()
{
    int n=GetN(),k=GetK(),t;
    t=n-1;
    while(t>0) {t-=k+1;}
    if(t+k+1>k) m=Second(); else m=Ans(t+k+1);
    while(m<n)
    {
        t+=k+1;
        m=Ans(t-m);
    }
    return 0;
}
