#include<stdio.h>

int field[101][101]={};

int chk(int x,int y,int a,int b)
{
    int t,r=0,stx=x,sty=y;
    //while(x<=b&&x>=0&&y<=a&&y>=0)
    while(1)
    {
        r=1;
        if(r==1&&x>b) {printf("E\n"); return 0;}
        else if(r==1&&x<1) {printf("W\n"); return 0;}
        else if(r==1&&y>a) {printf("S\n"); return 0;}
        else if(r==1&&y<1) {printf("N\n"); return 0;}
        else{
        t=field[y][x];
        if(t==1) y--;
        else if(t==2) x++;
        else if(t==3) y++;
        else x--;}
        if(r==1&&x==stx&&y==sty) {printf("NO\n"); return 0;}
    }
}

int main()
{
    int i,j,a,b,c,ball[21][3];
    scanf("%d %d %d",&a,&b,&c);
    for(i=1;i<=b;i++)
    {
        for(j=1;j<=a;j++)
        {
            scanf("%d",&field[i][j]);
        }
    }
    for(i=0;i<c;i++) scanf("%d %d",&ball[i][0],&ball[i][1]);
    for(i=1;i<=c;i++) chk(ball[i-1][0],ball[i-1][1],b,a);
    return 0;
}
