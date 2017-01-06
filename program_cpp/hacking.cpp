#include<iostream>
#include<cstdio>
#include "hacking.h" //Special header

using namespace std;

/*int sys[1000]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};

int GetN() {return 20;}
                                                                    //Debug functions for hacking.h
int CheckF(int a)
{
    if(sys[a]==1) return 1; else return 0;
}*/

int main()
{
    int n=GetN();
    int s=0,i,j,test;
    if(n<=10) s=1; else s=10;
    for(i=1;i<=n;i+=s)
    {
        test=CheckF(i);
        if(test==1) break;
    }
    if(test==1)
    {
        for(j=i-s;j<i;j++)
        {
            test=CheckF(j);
            if(test==1) break;
        }
    }
    else
    {
        if(i>n) i-=s;
        for(j=i;j<i+s;j++)
        {
            test=CheckF(j);
            if(test==1) break;
        }
    }
    printf("%d",j-1);
    return 0;
}
