#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct a{
    int ndr,lc,rc;
}aa;

queue<a> q;
a dat[300005]={};
int ans[100005]={},n;
char t[100005]={};

void chk(int str,int nd,int lim,int len)
{
    if(lim==len) {dat[str].ndr=nd; return;}
    if(t[lim-1]=='L')
    {
        dat[str].lc++;
        chk(str*2,nd,lim+1,len);
    }
    else if(t[lim-1]=='R')
    {
        dat[str].rc++;
        chk((str*2)+1,nd,lim+1,len);
    }
}

int main()
{
    int i,ta,tb,tc;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {scanf("%s",t); chk(1,i,1,strlen(t));}
    aa.ndr=1; aa.lc=1; aa.rc=n; q.push(aa);
    while(!q.empty())
    {
        aa=q.front(); q.pop();
        ta=aa.ndr; tb=aa.lc; tc=aa.rc;
        ans[dat[ta].ndr]=tb+dat[ta].lc;
    }
    for(i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
