#include<cstdio>
#include<queue>

struct a{
    int x,y;
}aa;

std::queue<a> q;
int n,m,ans=0;
char f[2005][2005]={};

void rem()
{
    int i,j;
    while(!q.empty())
    {
        aa=q.front(); q.pop(); i=aa.x; j=aa.y;
        if(f[i-1][j]=='1') {f[i-1][j]='0'; aa.x=i-1; aa.y=j; q.push(aa);}
        if(f[i+1][j]=='1') {f[i+1][j]='0'; aa.x=i+1; aa.y=j; q.push(aa);}
        if(f[i][j-1]=='1') {f[i][j-1]='0'; aa.x=i; aa.y=j-1; q.push(aa);}
        if(f[i][j+1]=='1') {f[i][j+1]='0'; aa.x=i; aa.y=j+1; q.push(aa);}
        if(f[i-1][j-1]=='1') {f[i-1][j-1]='0'; aa.x=i-1; aa.y=j-1; q.push(aa);}
        if(f[i-1][j+1]=='1') {f[i-1][j+1]='0'; aa.x=i-1; aa.y=j+1; q.push(aa);}
        if(f[i+1][j-1]=='1') {f[i+1][j-1]='0'; aa.x=i+1; aa.y=j-1; q.push(aa);}
        if(f[i+1][j+1]=='1') {f[i+1][j+1]='0'; aa.x=i+1; aa.y=j+1; q.push(aa);}
    }
}

int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) scanf(" %c",&f[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(f[i][j]=='1')
            {
                ans++; f[i][j]='0';
                aa.x=i; aa.y=j; q.push(aa);
                rem();
            }
        }
    }
    printf("%d",ans);
    return 0;
}
