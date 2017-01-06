#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int> q;
int f[105][10005]={},s[105][10005]={},n,m,k,chk[105]={};

void init(int a)
{
    int i;
    for(i=1;i<=i+k;i++)
    {
        if(i>m) return;
        if(f[a][i]!=0) {chk[f[a][i]]++; q.push(f[a][i]);}
    }
}

int main()
{
    int i,j,t=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) {scanf("%d",&f[i][j]); if(i==n) s[i][j]=f[i][j];}
    }
    for(i=n-1;i>0;i--)
    {
        for(j=1;j<=m;j++)
        {
            if(j==1) init(i+1);
            if(j-k-1>0) {if(f[i+1][j-k-1]!=0) {chk[f[i+1][j-k-1]]--;}}
            if(j+k+1<=m)
                {
                    if(f[i+1][j+k+1]!=0)
                        {
                            chk[f[i+1][j+k+1]]++;
                            q.push(f[i+1][j+k+1]);
                        }
                }
            if(!q.empty()) {while(chk[q.top()]==0) {q.pop(); if(q.empty()) break;}}
            s[i][j]=q.top()+f[i][j];
        }
    }
    for(i=1;i<=m;i++) if(s[1][i]>t) t=s[1][i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) printf("%d ",s[i][j]); printf("\n");
    }
    printf("%d",t);
    return 0;
}
