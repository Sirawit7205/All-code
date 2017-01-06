#include<cstdio>
#include<algorithm>

using namespace std;

struct a{
    int x,y;
    bool operator < (const a&T)const{
        return x < T.x;
    }
}aa;

a dat[100005]={},tmp[100005]={};
int n;
long long int mx=0,sav[100005]={};

void msrt(int l,int r)
{
    int i,j,x=0,mid=(l+r)/2,pa,pb;
    if(l==r) return;
    else if(r-l==1) {if(dat[l].y>dat[r].y) {mx+=dat[l].x+dat[r].x; swap(dat[l],dat[r]);} return;}
    else
    {
        msrt(l,mid); msrt(mid+1,r);
        pa=l; pb=mid+1;
        for(i=l;i<=r;i++)
        {
            if(pa>mid) {tmp[i]=dat[pb]; pb++;}
            else if(pb>r) {tmp[i]=dat[pa]; sav[dat[pa].y]+=x; pa++;}
            else if(dat[pa].y<=dat[pb].y) {tmp[i]=dat[pa]; sav[dat[pa].y]+=x; pa++;}
            else
            {
                x++; sav[dat[pb].y]+=mid-pa+1;
                tmp[i]=dat[pb]; pb++;
            }
        }
        for(i=l;i<=r;i++) dat[i]=tmp[i];
    }
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d",&dat[i].x,&dat[i].y);
    sort(dat,dat+n);
    msrt(0,n-1);
    for(i=0;i<n;i++) mx+=sav[dat[i].y]*dat[i].x;
    printf("%lld",mx);
    return 0;
}
