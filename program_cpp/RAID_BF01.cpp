#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>

int f[100][105]={};
bool chk[100][105][5005]={};

struct a
{
    int x,y,l;
} b;

std::queue<a> q;

int main()
{
    int i,j,m,n,x,y,l;
    scanf("%d %d",&m,&n);
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++) scanf("%d",&f[i][j]);
    }
    if(f[((m+1)/2)-1][1]==1)
    {
        b.x=((m+1)/2)-1;
        b.y=1;
        b.l=1;
        q.push(b);
        chk[((m+1)/2)-1][1][1]=true;
    }
    if(f[(m+1)/2][1]==1)
    {
        b.x=(m+1)/2;
        b.y=1;
        b.l=1;
        q.push(b);
        chk[(m+1)/2][1][1]=true;
    }
    if(f[((m+1)/2)+1][1]==1)
    {
        b.x=((m+1)/2)+1;
        b.y=1;
        b.l=1;
        q.push(b);
        chk[((m+1)/2)+1][1][1]=true;
    }
    while(not q.empty())
    {
        b=q.front();
        q.pop();
        if(b.x==(m+1)/2&&b.y==n)
        {
            printf("%d",b.l); return 0;
        }
        else
        {
            x=b.x;
            y=b.y;
            l=b.l;
            //printf("%d %d %d %d\n",x,y,l,f[x][y]);
            if(f[x][y-1]!=0&&chk[x][y-1][l+1]==false&&(l+1)%f[x][y-1]==0)
            {
                b.x=x;
                b.y=y-1;
                b.l=l+1;
                q.push(b);
                chk[x][y-1][l+1]=true;
            }
            if(f[x][y+1]!=0&&chk[x][y+1][l+1]==false&&(l+1)%f[x][y+1]==0)
            {
                b.x=x;
                b.y=y+1;
                b.l=l+1;
                q.push(b);
                chk[x][y+1][l+1]=true;
            }
            if(x%2!=0)
            {
                if(f[x-1][y]!=0&&chk[x-1][y][l+1]==false&&(l+1)%f[x-1][y]==0)
                {
                    b.x=x-1;
                    b.y=y;
                    b.l=l+1;
                    q.push(b);
                    chk[x-1][y][l+1]=true;
                }
                if(f[x+1][y]!=0&&chk[x+1][y][l+1]==false&&(l+1)%f[x+1][y]==0)
                {
                    b.x=x+1;
                    b.y=y;
                    b.l=l+1;
                    q.push(b);
                    chk[x+1][y][l+1]=true;
                }
                if(f[x-1][y+1]!=0&&chk[x-1][y+1][l+1]==false&&(l+1)%f[x-1][y+1]==0)
                {
                    b.x=x-1;
                    b.y=y+1;
                    b.l=l+1;
                    q.push(b);
                    chk[x-1][y+1][l+1]=true;
                }
                if(f[x+1][y+1]!=0&&chk[x+1][y+1][l+1]==false&&(l+1)%f[x+1][y+1]==0)
                {
                    b.x=x+1;
                    b.y=y+1;
                    b.l=l+1;
                    q.push(b);
                    chk[x+1][y+1][l+1]=true;
                }
            }
            else
            {
                if(f[x-1][y-1]!=0&&chk[x-1][y-1][l+1]==false&&(l+1)%f[x-1][y-1]==0)
                {
                    b.x=x-1;
                    b.y=y-1;
                    b.l=l+1;
                    q.push(b);
                    chk[x-1][y-1][l+1]=true;
                }
                if(f[x+1][y-1]!=0&&chk[x+1][y-1][l+1]==false&&(l+1)%f[x+1][y-1]==0)
                {
                    b.x=x+1;
                    b.y=y-1;
                    b.l=l+1;
                    q.push(b);
                    chk[x+1][y-1][l+1]=true;
                }
                if(f[x-1][y]!=0&&chk[x-1][y][l+1]==false&&(l+1)%f[x-1][y]==0)
                {
                    b.x=x-1;
                    b.y=y;
                    b.l=l+1;
                    q.push(b);
                    chk[x-1][y][l+1]=true;
                }
                if(f[x+1][y]!=0&&chk[x+1][y][l+1]==false&&(l+1)%f[x+1][y]==0)
                {
                    b.x=x+1;
                    b.y=y;
                    b.l=l+1;
                    q.push(b);
                    chk[x+1][y][l+1]=true;
                }
            }
        }
    }
    return 0;
}
