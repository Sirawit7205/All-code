#include<iostream>
#include<cstdio>

int f[205][205]={},val[40005]={},lnklist[40005][10]={},sta,pc=0,m,n,re=0;

void chk(int x,int y,int c,int s,int p)
{
    int i;
    if((f[x][y]!=0&&re==0)||x<1||y<1||x>m||y>n||pc==1) {pc=1; return;} else f[x][y]=s;
    for(i=1;i<=lnklist[s][0];i+=2)
    {
        if(lnklist[s][i+1]==1&&p!=lnklist[s][i]) chk(x-1,y,c+1,lnklist[s][i],s);
        else if(lnklist[s][i+1]==2&&p!=lnklist[s][i]) chk(x,y-1,c+1,lnklist[s][i],s);
        else if(lnklist[s][i+1]==3&&p!=lnklist[s][i]) chk(x,y+1,c+1,lnklist[s][i],s);
        else if(lnklist[s][i+1]==4&&p!=lnklist[s][i]) chk(x+1,y,c+1,lnklist[s][i],s);
    }
}

int main()
{
    int i,j,ta,tb;
    char mode;
    scanf("%d %d",&m,&n);
    for(i=1;i<m*n;i++)
    {
        scanf("%d %c %d",&ta,&mode,&tb);
        val[tb]=1;
        lnklist[ta][lnklist[ta][0]+1]=tb;
        lnklist[tb][lnklist[tb][0]+1]=ta;
        if(mode=='U') {lnklist[ta][lnklist[ta][0]+2]=4; lnklist[tb][lnklist[tb][0]+2]=1;}
        else {lnklist[ta][lnklist[ta][0]+2]=3; lnklist[tb][lnklist[tb][0]+2]=2;}
        lnklist[ta][0]+=2; lnklist[tb][0]+=2;
    }
    for(i=0;i<m*n;i++) if(val[i]==0) {sta=i; break;}
    restart:; chk(1,1,0,sta,-1);
    if(pc==1) {for(i=sta+1;i<m*n;i++) if(val[i]==0) {sta=i; break;} re=1; pc=0; goto restart;}
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++) printf("%d ",f[i][j]);
        printf("\n");
    }
    return 0;
}
