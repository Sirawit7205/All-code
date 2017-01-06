#include<cstdio>

int f[105][10005]={},s[105][10005]={},n,m,k;

int rec(int lvl,int ln)
{
    int i,t=0,tt;
    if(lvl==n) {s[lvl][ln]=f[lvl][ln]; return f[lvl][ln];}
    for(i=ln-k;i<=ln+k;i++)
    {
        if(i<1) continue; else if(i>m) break;
        else
        {
            if(s[lvl+1][i]!=-1) tt=s[lvl+1][i]+f[lvl][ln];
            else tt=rec(lvl+1,i)+f[lvl][ln];
            if(tt>t) t=tt;
        }
    }
    s[lvl][ln]=t;
    return t;
}

int main()
{
    int i,j,t=0,tt;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) {scanf("%d",&f[i][j]); s[i][j]=-1;}
    }
    for(i=1;i<=m;i++) {tt=rec(1,i); if(tt>t) t=tt;}
    printf("%d",t);
    return 0;
}
