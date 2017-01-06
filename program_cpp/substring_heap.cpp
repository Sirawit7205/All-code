#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

priority_queue<long long int, std::vector<int>, std::greater<int> > q;
char dat[300005]={};
long long int f[30]={},cway[30]={},n=0;

void enq()
{
    long long int i,c=0,in=0,t;
    for(i=1;i<=26;i++) if(f[i]!=0) {q.push(f[i]); c++;}
    while(not q.empty())
    {
        t=q.top(); q.pop();
        if(cway[c]==0) n++;
        cway[c]+=t-in;
        in=t;
        c--;
    }
}

int main()
{
    long long int i,len;
    scanf("%s",dat);
    len=strlen(dat);
    for(i=1;i<=len;i++)
    {
        if(f[dat[i-1]-96]==0||(f[dat[i-1]-96]!=0&&f[dat[i-1]-96]<i)) f[dat[i-1]-96]=i;
        enq();
    }
    printf("%lld\n",n);
    for(i=1;i<=26;i++) if(cway[i]!=0) printf("%lld\n",cway[i]);
    return 0;
}
