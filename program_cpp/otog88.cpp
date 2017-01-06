#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

struct a{
    long long int pos,num;
    bool operator < (const a&T) const{
        return pos < T.pos;
    }
};

a x[50005]={},y[50005]={},tmp,tmpb;
long long int m,ll,temp;
bool chk[50005][3]={};

int main()
{
    long long int n,i,j,ta=0,tb=0,ra,rb,tta,ttb;
    long long int ca,cb;
    scanf("%lld %lld %lld",&n,&m,&ll);
    for(i=0;i<m;i++)
    {
        scanf("%lld",&temp); if(chk[temp][0]==false) {chk[temp][0]=true; x[ta].num=i+1; x[ta].pos=temp; ta++;}
    }
    for(j=0;j<ll;j++)
    {
        scanf("%lld",&temp); if(chk[temp][1]==false) {chk[temp][1]=true; y[tb].num=j+i+1; y[tb].pos=temp; tb++;}
    }
    sort(x,x+ta); sort(y,y+tb);
    tta=ta; ttb=tb;
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&ta,&tb); tmp.pos=ta; tmpb.pos=tb;
        ra=lower_bound(x,x+tta,tmp)-x; rb=lower_bound(y,y+ttb,tmpb)-y;
        if(ra==tta) ra--;
        else if(ra!=0&&x[ra].pos!=ta) {if(ta-x[ra-1].pos<x[ra].pos-ta) ra--; else if(ta-x[ra-1].pos==x[ra].pos-ta&&x[ra-1].num<x[ra].num) ra--;}
        if(rb==ttb) rb--;
        else if(rb!=0&&y[rb].pos!=tb) {if(tb-y[rb-1].pos<y[rb].pos-tb) rb--; else if(tb-y[rb-1].pos==y[rb].pos-tb&&y[rb-1].num<y[rb].num) rb--;}
        ca=((ta-x[ra].pos)*(ta-x[ra].pos))+(tb*tb); cb=(ta*ta)+((tb-y[rb].pos)*(tb-y[rb].pos));
        if(ca==cb) {if(x[ra].num<=y[rb].num) printf("%lld\n",x[ra].num); else printf("%lld\n",y[rb].num);}
        else if(ca<cb) printf("%lld\n",x[ra].num);
        else printf("%lld\n",y[rb].num);
    }
    return 0;
}
