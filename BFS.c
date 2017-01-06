#include<stdio.h>
#include<conio.h>

char b[51][51]={};
int r[51][51]={};
struct a{
    int x;
    int y;
    int d;
};

struct a q[1001];

int main()
{
    int i,j,m,n,top=0,bot=1,x,y;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&q[0].x,&q[0].y);
    q[0].d=1;
    for(i=0;i<m;i++)
    {
        scanf(" %s",b[i]);
        for(j=0;j<n;j++)
        {
            r[i][j]=b[i][j]-48;
        }
    }
    while(top!=bot)
    {
        x=q[top].y; y=q[top].x;
        r[x][y]=q[top].d;
        if(x-1>=0&&r[x-1][y]==0) {q[bot].y=x-1; q[bot].x=y; q[bot].d=q[top].d+1; bot++;} if(bot==1000) {bot=0;}
        if(x+1<n&&r[x+1][y]==0) {q[bot].y=x+1; q[bot].x=y; q[bot].d=q[top].d+1; bot++;} if(bot==1000) {bot=0;}
        if(y-1>=0&&r[x][y-1]==0) {q[bot].y=x; q[bot].x=y-1; q[bot].d=q[top].d+1; bot++;} if(bot==1000) {bot=0;}
        if(y+1<m&&r[x][y+1]==0) {q[bot].y=x; q[bot].x=y+1; q[bot].d=q[top].d+1; bot++;} if(bot==1000) {bot=0;}
        top++;
        if(top==1000) {top=0;}
        /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d",r[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    /*scanf("%d %d",&x,&y);
    printf("%d\n",b[x][y]);*/
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
    return 0;
}
