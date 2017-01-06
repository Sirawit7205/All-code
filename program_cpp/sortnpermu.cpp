#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

map<int,int> mp[100000];

struct a_s
{
    int ord,dat;
}ans[100001];

bool cmp(const a_s a,const a_s b)
 {
     return a.dat > b.dat;
 }
int c=1,val,lp[100001]={};

int chk(int n)
{
    int i,t,tt=0,b=mp[n].size();
    //if(i==b) return 0;
    if(lp[n]==val) return 1; else {if(ans[n].dat==0) lp[n]=val;}
    if(ans[n].dat!=0) return 0;
    for(i=0;i<b;i++)
    {
        t=mp[n][i];
        tt=chk(t);
    }
    if(tt==1) return 1;
    if(ans[n].dat==0) {ans[n].dat=c; ans[n].ord=n; lp[n]=0; c++; return 0;}
}
int main()
{
    int i,n,m,s,ta,tb,tc;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&ta,&tb,&tc);
        s=mp[ta].size();
        mp[ta].insert(pair<int,int>(s,tb));
        s=mp[tb].size();
        mp[tb].insert(pair<int,int>(s,tc));
        s=mp[ta].size();
        mp[ta].insert(pair<int,int>(s,tc));
    }
    for(i=1;i<=n;i++)
    {
        val=i; ta=chk(i);
        if(ta==1) {printf("no"); return 0;}
    }
    sort(ans+1,ans+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        printf("%d ",ans[i].ord);
    }
    return 0;
}
