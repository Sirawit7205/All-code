#include<iostream>
#include<cstdio>

using namespace std;

int cache[10000005]={};

int main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    cache[2]=1;
    for(i=3;i<=a;i++)
    {
        if(i%2==0)
        {
            cache[i]=(cache[i-1]+cache[i/2])%b;
        }
        else
        {
            cache[i]=cache[i-1]%b;
        }
    }
    printf("%d",cache[a]);
    return 0;
}
