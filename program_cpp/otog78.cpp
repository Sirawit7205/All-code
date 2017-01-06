#include<cstdio>
#include<vector>

struct a{
    int x,y,l;
}aa;

std::vector<a> v;
int head[105]={};

int findh(int nd)
{
    if(head[nd]==nd) return nd;
    else return head[nd]=findh(head[nd]);
}

int main()
{
    int i,n,m,s,p,q,r;
    long long int tt=0;
    scanf("%d %d %d",&n,&m,&s);
    for(i=1;i<=n;i++) head[i]=i;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&p,&q,&r);
        aa.x=p; aa.y=q; aa.l=r; v.push_back(aa); tt+=r;
    }
    r=1; i=0;
    while(r<=m)
    {
        aa=v[i];
        p=findh(aa.x); q=findh(aa.y);
        if(p==q) {printf("YES"); return 0;}
        else {head[p]=q; i++; r++;}
    }
    if(tt>=s) printf("YES"); else printf("NO");
    return 0;
}
