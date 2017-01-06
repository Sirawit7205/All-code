#include<cstdio>
#include<queue>

using namespace std;

struct a{
    long long int val,pos;
    bool operator < (const a&T)const{
        return val > T.val;
    }
}aa;

priority_queue<a> q;
int dat[500005]={};

int main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&dat[i]);
    for(i=2;i<=k+1;i++) {aa.pos=i; aa.val=dat[i]+dat[1]; q.push(aa);}
    for(i=k+2;i<=n;i++)
    {
        while(i-q.top().pos>k) q.pop();
        aa.pos=i; aa.val=dat[i]+q.top().val; q.push(aa);
        if(i==n) printf("%lld",aa.val);
    }
    return 0;
}
