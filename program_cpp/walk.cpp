#include<iostream>
#include<cstdio>

using namespace std;

int d[30][700]={},c[30]={},w[30]={};

int main()
{
    int i,n,str=-1,t,prev,j,ti,tj,m=0;
    char ta,tb;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c%c",&ta,&tb);
        ti=ta-64; tj=tb-64;
        //if(ti<0||tj<0) return 0;
        d[ti][c[ti]]=tj;
        d[tj][c[tj]]=ti;
        c[ti]++; c[tj]++;
    }
    for(i=1;i<=26;i++) if(c[i]%2==1) {str=i; break;}
    if(str==-1) for(i=1;i<=26;i++) if(c[i]!=0) {str=i; break;}
    while(1)
    {
        if(c[str]<=w[str]) break;
        printf("%c ",str+64);
        for(j=1;j<=c[str];j++)
            {
                if(d[str][w[str]]!=prev||(c[str]==2&&d[str][0]==prev&&d[str][1]==prev))
                {
                    if(c[d[str][w[str]]]==1&&m!=n-1)
                    {
                        d[str][c[str]]=d[str][w[str]]; c[str]++; w[str]++;
                    }
                    else
                    {
                        t=d[str][w[str]]; w[str]++; break;
                    }
                }
                else w[str]++;
            }
        prev=str; str=t; m++;
    }
    return 0;
}
