#include<cstdio>
#include<queue>

using namespace std;

struct a{
    int x,y,l;
}aa;

queue<a> q;

int f[105][105]={},n,m;
bool chk[105][105][5005]={};

int main()
{
    int i,j,ta,tb,tc;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) scanf("%d",&f[i][j]);
    }
    if(f[(n-1)/2][0]!=0&&f[(n-1)/2][0]==1) {aa.x=(n-1)/2; aa.y=0; aa.l=1; q.push(aa); chk[(n-1)/2][0][1]=true;}
    if(f[((n-1)/2)-1][0]!=0&&f[((n-1)/2)-1][0]==1) {aa.x=((n-1)/2)-1; aa.y=0; aa.l=1; q.push(aa); chk[((n-1)/2)-1][0][1]=true;}
    if(f[((n-1)/2)+1][0]!=0&&f[((n-1)/2)+1][0]==1) {aa.x=((n-1)/2)+1; aa.y=0; aa.l=1; q.push(aa); chk[((n-1)/2)+1][0][1]=true;}
    while(!q.empty())
    {
        aa=q.front(); q.pop(); ta=aa.x; tb=aa.y; tc=aa.l;
        //printf("%d %d %d\n",ta,tb,tc);
        if(ta==(n-1)/2&&tb==m-1) break;
        if(ta%2!=0)
        {
            if(tb>0&&f[ta][tb-1]!=0&&(tc+1)%f[ta][tb-1]==0&&chk[ta][tb-1][tc+1]==false) {aa.x=ta; aa.y=tb-1; aa.l=tc+1; q.push(aa); chk[ta][tb-1][tc+1]=true;}
            if(tb<m-1&&f[ta][tb+1]!=0&&(tc+1)%f[ta][tb+1]==0&&chk[ta][tb+1][tc+1]==false) {aa.x=ta; aa.y=tb+1; aa.l=tc+1; q.push(aa); chk[ta][tb+1][tc+1]=true;}
            if(ta>0&&tb>0&&f[ta-1][tb-1]!=0&&(tc+1)%f[ta-1][tb-1]==0&&chk[ta-1][tb-1][tc+1]==false) {aa.x=ta-1; aa.y=tb-1; aa.l=tc+1; q.push(aa); chk[ta-1][tb-1][tc+1]=true;}
            if(ta>0&&f[ta-1][tb]!=0&&(tc+1)%f[ta-1][tb]==0&&chk[ta-1][tb][tc+1]==false) {aa.x=ta-1; aa.y=tb; aa.l=tc+1; q.push(aa); chk[ta-1][tb][tc+1]=true;}
            if(ta<n-1&&tb>0&&f[ta+1][tb-1]!=0&&(tc+1)%f[ta+1][tb-1]==0&&chk[ta+1][tb-1][tc+1]==false) {aa.x=ta+1; aa.y=tb-1; aa.l=tc+1; q.push(aa); chk[ta+1][tb-1][tc+1]=true;}
            if(ta<n-1&&f[ta+1][tb]!=0&&(tc+1)%f[ta+1][tb]==0&&chk[ta+1][tb][tc+1]==false) {aa.x=ta+1; aa.y=tb; aa.l=tc+1; q.push(aa); chk[ta+1][tb][tc+1]=true;}
        }
        else
        {
            if(tb>0&&f[ta][tb-1]!=0&&(tc+1)%f[ta][tb-1]==0&&chk[ta][tb-1][tc+1]==false) {aa.x=ta; aa.y=tb-1; aa.l=tc+1; q.push(aa); chk[ta][tb-1][tc+1]=true;}
            if(tb<m-1&&f[ta][tb+1]!=0&&(tc+1)%f[ta][tb+1]==0&&chk[ta][tb+1][tc+1]==false) {aa.x=ta; aa.y=tb+1; aa.l=tc+1; q.push(aa); chk[ta][tb+1][tc+1]=true;}
            if(ta>0&&f[ta-1][tb]!=0&&(tc+1)%f[ta-1][tb]==0&&chk[ta-1][tb][tc+1]==false) {aa.x=ta-1; aa.y=tb; aa.l=tc+1; q.push(aa); chk[ta-1][tb][tc+1]=true;}
            if(ta>0&&tb<m-1&&f[ta-1][tb+1]!=0&&(tc+1)%f[ta-1][tb+1]==0&&chk[ta-1][tb+1][tc+1]==false) {aa.x=ta-1; aa.y=tb+1; aa.l=tc+1; q.push(aa); chk[ta-1][tb+1][tc+1]=true;}
            if(ta<n-1&&f[ta+1][tb]!=0&&(tc+1)%f[ta+1][tb]==0&&chk[ta+1][tb][tc+1]==false) {aa.x=ta+1; aa.y=tb; aa.l=tc+1; q.push(aa); chk[ta+1][tb][tc+1]=true;}
            if(ta<n-1&&tb<m-1&&f[ta+1][tb+1]!=0&&(tc+1)%f[ta+1][tb+1]==0&&chk[ta+1][tb+1][tc+1]==false) {aa.x=ta+1; aa.y=tb+1; aa.l=tc+1; q.push(aa); chk[ta+1][tb+1][tc+1]=true;}
        }
    }
    printf("%d",aa.l);
    return 0;
}
