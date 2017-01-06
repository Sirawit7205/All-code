#include<cstdio>

int s,posx,posy;

int chk(int x,int y,int sz,int tx,int ty)
{
    if(tx>=x&&tx<=x+sz-1&&ty>=y&&ty<=y+sz-1) return 1;
    else return 0;
}

int div(int x,int y,int pos,int sz,int tx,int ty)
{
    int a,b,d,e,px,py,c;
    if(chk(x,y,sz,tx,ty)==0)
    {
        if(pos==1) {px=x+sz-1; py=y+sz-1; c=1;}
        else if(pos==2) {px=x; py=y+sz-1; c=2;}
        else if(pos==3) {px=x+sz-1; py=y; c=3;}
        else {px=x; py=y; c=4;}
    }
    else{px=tx; py=ty; c=0;}
    if(sz==2)
    {
        if(px==x&&py==y) {printf("0 %d %d\n",x,y); return c;}
        else if(px==x+1&&py==y) {printf("1 %d %d\n",x,y); return c;}
        else if(px==x&&py==y+1) {printf("2 %d %d\n",x,y); return c;}
        else if(px==x+1&&py==y+1) {printf("3 %d %d\n",x,y); return c;}
    }
    a=div(x,y,1,sz/2,px,py); b=div(x+sz/2,y,2,sz/2,px,py); d=div(x,y+sz/2,3,sz/2,px,py); e=div(x+sz/2,y+sz/2,4,sz/2,px,py);
    if(c==0)
    {
        if(a==0) printf("0 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        else if(b==0) printf("1 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        else if(d==0) printf("2 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        else if(e==0) printf("3 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        return 0;
    }
    else
    {
        if(pos==1) printf("3 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        else if(pos==2) printf("2 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        else if(pos==3) printf("1 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        else printf("0 %d %d\n",x+(sz/2)-1,y+(sz/2)-1);
        return 1;
    }
}

int main()
{
    int x;
    scanf("%d %d %d",&s,&posx,&posy);
    printf("%d\n",(s*s)/3);
    if(posx>=0&&posx<=s/2-1&&posy>=0&&posy<=s/2-1) x=4;
    else if(posx>=s/2&&posx<=s*2-1&&posy>=0&&posy<=s/2-1) x=3;
    else if(posx>=0&&posx<=s/2-1&&posy>=s/2&&posy<=s*2-1) x=2;
    else x=1;
    x=div(0,0,x,s,posx,posy);
    return 0;
}
