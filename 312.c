#include<stdio.h>

int chk[1000001]={},f[1002][1002]={},n;

void recur(int x,int y,int s)
{
    if(x==0||y==0||x>n||y>n||f[x][y]==-1||f[x][y]!=s) return;
    else
    {
        f[x][y]=-1;
        if(x-1!=0&&f[x-1][y]==0&&(f[x-1][y-1]<=0||f[x-1][y-1]>=s)&&(f[x-1][y+1]<=0||f[x-1][y+1]>=s)&&(f[x-2][y]<=0||f[x-2][y]>=s)) f[x-1][y]=s+1;
        if(x+1<=n&&f[x+1][y]==0&&(f[x+1][y-1]<=0||f[x+1][y-1]>=s)&&(f[x+1][y+1]<=0||f[x+1][y+1]>=s)&&(f[x+2][y]<=0||f[x+2][y]>=s)) f[x+1][y]=s+1;
        if(y-1!=0&&f[x][y-1]==0&&(f[x-1][y-1]<=0||f[x-1][y-1]>=s)&&(f[x+1][y-1]<=0||f[x+1][y-1]>=s)&&(f[x][y-2]<=0||f[x][y-2]>=s)) f[x][y-1]=s+1;
        if(y+1<=n&&f[x][y+1]==0&&(f[x-1][y+1]<=0||f[x-1][y+1]>=s)&&(f[x+1][y+1]<=0||f[x+1][y+1]>=s)&&(f[x][y+2]<=0||f[x][y+2]>=s)) f[x][y+1]=s+1;
        chk[s]++;
        recur(x-1,y,s+1);
        recur(x+1,y,s+1);
        recur(x,y-1,s+1);
        recur(x,y+1,s+1);
    }
}

int main()
{
    int i,m,q,a,b;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        f[b][a]=-1;
    }
    scanf("%d %d",&a,&b);
    recur(a,b,0);
    b=0;
    while(chk[b]!=0) {chk[b]+=chk[b-1]; b++;}
    for(i=0;i<q;i++)
    {
        scanf("%d",&a);
        if(a>=b) printf("%d\n",chk[b-1]);
        else printf("%d\n",chk[a]);
    }
    return 0;
}
