#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v[200001];
int n,k,m,l,val[200005]={},mx=0,use=0;

void run(int pl,int h)
{
    int i,x=-1,y=-1;
    if(h>=m) {if(val[pl]>mx) {mx=val[pl]; use=1;} return;}
    for(i=0;i<v[pl-1].size();i++) if(v[pl-1][i]>h) {x=v[pl-1][i]; break;}
    for(i=0;i<v[pl+1].size();i++) if(v[pl+1][i]>h) {y=v[pl+1][i]; break;}
    if(x==-1||(y<x&&x!=-1)) run(pl+1,y); else run(pl-1,x);
}

int main()
{
    int i,ta,tb,j,jj,ii,x,xx;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&val[i]);
    for(i=1;i<=k;i++) {scanf("%d %d",&ta,&tb); v[ta].push_back(tb);}
    for(i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    scanf("%d",&l); ii=1;
    while(ii<m)
    {
        j=-1; jj=-1; x=-1; xx=-1;
        if(l-2>=1) for(i=0;i<v[l-2].size();i++) if(v[l-2][i]>ii) {j=v[l-2][i]; break;}
        if(l+2<=n) for(i=0;i<v[l+2].size();i++) if(v[l+2][i]>ii) {jj=v[l+2][i]; break;}
        if(l-1>=1) for(i=0;i<v[l-1].size();i++) if(v[l-1][i]>ii) {x=v[l-1][i]; break;}
        if(l+1<=n) for(i=0;i<v[l+1].size();i++) if(v[l+1][i]>ii) {xx=v[l+1][i]; break;}
        if(j!=-1) run(l-1,ii-1); if(jj!=-1) run(l+1,ii-1);
        if(j==-1&&jj!=-1) ii=jj; else if(j!=-1&&jj==-1) ii=j; else if(j!=-1&&jj!=-1&&j<=jj) ii=j; else if(j!=-1&&jj!=-1&&j>jj) ii=jj;
        else if(j==-1&&jj==-1)
        {
            if(x!=-1&&xx==-1) {ii=x; l-=1;} else if(x==-1&&xx!=-1) {ii=xx; l+=1;} else if(x!=-1&&xx!=-1&&x<=xx) {ii=x; l-=1;} else if(x!=-1&&xx!=-1&&x>xx) {ii=xx; l+=1;}
            else ii=m;
        }
    }
    if(val[l]>mx) {mx=val[l]; use=0;}
    printf("%d\n",mx);
    if(use==0) printf("NO"); else printf("USE");
    return 0;
}
