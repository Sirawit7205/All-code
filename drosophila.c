#include<stdio.h>
#include<string.h>

char map[51][51]={};
int n,m;

void finddoor(int y,int x,int cy,int cx)
{
    if(map[y][x]>=65&&map[y][x]<=90) {printf("%c",map[y][x]); return;}
    if(map[y][x]=='1') return;
    if(y-1>=0&&cy!=y-1) finddoor(y-1,x,y,x);
    if(x-1>=0&&cx!=x-1) finddoor(y,x-1,y,x);
    if(y+1<n&&cy!=y-1) finddoor(y+1,x,y,x);
    if(x+1<m&&cx!=x-1) finddoor(y,x-1,y,x);
}

int main()
{
    int i,y,x;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);
    for(i=0;i<m;i++) scanf("%s",map[i]);
    finddoor(y,x,y,x);
    return 0;
}
