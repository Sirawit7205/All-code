#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> a[100005]={};

int dat[100005]={},bon[100005]={};

void chk(int x,int p)
{
    int i,d,y=a[x].size();
    dat[x]=bon[x]+dat[p];
    for(i=0;i<y;i++)
    {
        d=a[x][i];
        chk(d,x);
    }
    if(y==0) return;
}

int main()
{
    int i,ta,n,m,tb;
    scanf("%d %d",&n,&m);
    for(i=0;i<n-1;i++) {scanf("%d %d",&ta,&tb); a[tb].push_back(ta);}
    for(i=0;i<m;i++) {scanf("%d %d",&ta,&tb); bon[ta]+=tb;}
    chk(1,0);
    for(i=1;i<=n;i++) printf("%d\n",dat[i]);
    return 0;
}
