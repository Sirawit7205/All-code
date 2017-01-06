#include<iostream>
#include<cstdio>

using namespace std;

char dat[1005]={};
short mem[1005][1005]={};
int m;

int recur(int a,int b)
{
    int i,t=0,ma=0;
    if(a==b||(b==a+1&&dat[a]!=dat[b])) return 0;
    else if(b==a+1&&dat[a]==dat[b]) return 1;
    if(dat[a]==dat[b]) if(mem[a][b]!=0) return mem[a][b]; else return mem[a][b]=recur(a+1,b-1)+1;
    else
    {
        for(i=a+1;i<=b;i++)
            {
                if(mem[a][i-1]==0) mem[a][i-1]=recur(a,i-1);
                if(mem[i][b]==0) mem[i][b]=recur(i,b);
                t=mem[a][i-1]+mem[i][b];
                if(t>ma) ma=t;
            }
        return ma;
    }
}

int main()
{
    int i,a;
    scanf("%d",&m);
    for(i=0;i<m;i++) scanf(" %c",&dat[i]);
    a=recur(0,m-1);
    printf("%d",a);
    return 0;
}
