#include<cstdio>
#include<algorithm>

using namespace std;

struct ax{
    int a,b,p;
    bool operator < (const ax&T)const{
        return b < T.b;
    }
}aa;

int n;
ax d[100005]={};

int last(int l,int r,int f)
{
    int mid=(l+r)/2;
    while(l<r)
    {
        //if(l==r&&d[mid].b>=f) return -1; else return l;
        if(d[mid].b<f)
        {
            if(d[mid+1].b<f) l=mid+1;
            else return mid;
        }
        else r=mid-1;
        mid=(l+r)/2;
    }
    return -1;
}

int main()
{
    int i,j,x,mx=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d %d",&d[i].a,&d[i].b,&d[i].p);
    sort(d,d+n);
    for(i=1;i<n;i++)
    {
        x=last(0,i-1,d[i].a);
        t=d[i].p; if(x!=-1) t+=d[x].p;
        d[i].p=max(t,d[i-1].p);
    }
    for(i=0;i<n;i++)
    {
        if(d[i].p>mx) mx=d[i].p;
    }
    printf("%d",mx);
    return 0;
}
