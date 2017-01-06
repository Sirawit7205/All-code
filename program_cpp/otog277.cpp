#include<cstdio>
#include<algorithm>

using namespace std;

struct a{
    long long int v;
    int idx;
    bool operator < (const a&T)const{
        return v < T.v;
    }
}hsh[100005];

int ans[100005]={},k,n,m,anscnt=0,use[100005]={},cuse=1;
long long int ccnt=0,con=1;
char cat[35]={},dat[1000005]={};

void calc(int p,int mode)
{
    int x=1,i;
    for(i=n-1;i>=0;i--)
    {
        if(mode==0)
        {
            hsh[p].v+=x*(cat[i]-48);
            x*=2;
        }
        else
        {
            ccnt+=x*(dat[i]-48);
            x*=2;
        }
    }
    if(con==1) con=x/2;
}

int srch(long long int v)
{
    int l,r,mid;
    l=0; r=k-1; mid=(l+r)/2;
    while(l<=r)
    {
        if(hsh[mid].v==v) return hsh[mid].idx;
        else if(hsh[mid].v<v) l=mid+1;
        else r=mid-1;
        mid=(l+r)/2;
    }
    return -1;
}

int main()
{
    int i,j,l,t;
    scanf("%d %d",&k,&n);
    for(i=0;i<k;i++)
    {
        scanf("%s",cat);
        hsh[i].idx=i;
        calc(i,0);
    }
    sort(hsh,hsh+k);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&l);
        scanf("%s",dat);
        ccnt=0,anscnt=0; cuse++;
        calc(i,1);
        for(j=n-1;j<l;j++)
        {
            t=srch(ccnt);
            if(t!=-1)
            {
                if(use[t]!=cuse)
                {
                    use[t]=cuse;
                    ans[anscnt]=t;
                    anscnt++;
                }
            }
            ccnt-=con*(dat[j-n+1]-48); ccnt*=2; ccnt+=(dat[j+1]-48);
        }
        if(anscnt==0) printf("OK\n");
        else
        {
            sort(ans,ans+anscnt);
            for(j=0;j<anscnt;j++) printf("%d ",ans[j]+1);
            printf("\n");
        }
    }
    return 0;
}
