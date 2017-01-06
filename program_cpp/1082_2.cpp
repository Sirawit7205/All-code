#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct dat
{
    int fr,to,co;
};

dat a[1000100];
int root[100001]= {};

bool cmp (const dat d,const dat e)
{
    return d.co<e.co;
}

int chkl(int a)
{
    if(root[a]!=a) return chkl(root[a]);
    else return a;
}

int main()
{
    int i,n,m,k=0;
    scanf("%d %d",&n,&m);
    for(i=0; i<=n; i++) root[i]=i;
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&a[i].fr,&a[i].to,&a[i].co);
    }
    sort(a,a+m,cmp);
    for(i=0; i<m; i++)
    {
        if(chkl(a[i].fr)!=chkl(a[i].to))
        {
            printf("%d %d\n",a[i].fr,a[i].to);
            root[chkl(a[i].fr)]=chkl(a[i].to); k++;
        }
        if(k==n-1) break;
    }
    //for(it=dat.begin();it!=dat.end();++it) cout << it->fr << it->to << it->co << endl;
    return 0;
}


