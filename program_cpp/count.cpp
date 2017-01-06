#include<iostream>
#include<cstdio>
//#include "count.h"

using namespace std;
int cur=0;
int GetN() {return 10;}
int GetK() {return 3;}
int Second()
{
    int i;
    printf("P2: ");
    scanf("%d",&i);
    return i;
}
int Ans(int i)
{
    int a;
    i+=cur;
    printf("Current=%d\nP2: ",i);
    scanf("%d",&a);
    return i+a;
}

int main()
{
    int i,n=GetN(),k=GetK();
    if(n==1) {cur=Second();}
    if(k==1)
    {
        while(1) cur=Ans(1);
    }
    if(n<=k) {cur=Ans(n-1);}
    else
    {
        cur=Second();
        while(1)
        {
            if(cur+(k*2)>=n)
            {
                if(n-cur<=k) cur=Ans(n-cur-1);
                else
                {
                    for(i=1;i<=k;i++){
                    if(cur+i==n-1) break;
                    else if(n-(cur+i+k)<0) continue;
                    else if(n-(cur+i+k)<k) break;}
                    cur=Ans(i);
                }
            }
            else cur=Ans(k);
        }
    }
    return 0;
}
