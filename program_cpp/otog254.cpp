#include<cstdio>
#include<cmath>
//#include"hacking.h"

int GetN() {return 1000;}

int CheckF(int a) {int tar=567; if(a<=tar) return 0; else return 1;}

int main()
{
    int i=0,j,n=GetN(),x;
    x=sqrt(n);
    while(1)
    {
        if(i+x>n) i=n; else i+=x;
        if(CheckF(i)==1) break;
    }
    i-=x;
    for(j=i;j<=i+x;j++)
    {
        if(CheckF(j)==1) break;
    }
    printf("%d",j-1);
    return 0;
}

