#include<cstdio>

int n,m,f[305][305]={},ans[1500]={},ansb=0;

void chk(int x,int y,int r,int l)
{
    if(x==-1) {if(f[x+1][y]!=22) f[x+1][y]=0; ans[ansb]=l; ansb++; return;}
    else if(y==-1) {if(f[x][y+1]!=21) f[x][y+1]=0; ans[ansb]=l; ansb++; return;}
    else if(x==n) {if(f[x-1][y]!=22) f[x-1][y]=0; ans[ansb]=l; ansb++; return;}
    else if(y==m) {if(f[x][y-1]!=21) f[x][y-1]=0; ans[ansb]=l; ansb++; return;}
    if(f[x][y]==11&&r==1) chk(x,y-1,3,l+1); else if(f[x][y]==11&&r==2) chk(x-1,y,4,l+1);
    else if(f[x][y]==12&&r==1) chk(x,y+1,2,l+1); else if(f[x][y]==12&&r==3) chk(x-1,y,4,l+1);
    else if(f[x][y]==13&&r==2) chk(x+1,y,1,l+1); else if(f[x][y]==13&&r==4) chk(x,y-1,3,l+1);
    else if(f[x][y]==14&&r==3) chk(x+1,y,1,l+1); else if(f[x][y]==14&&r==4) chk(x,y+1,2,l+1);
    else if(f[x][y]==21&&r==1) chk(x+1,y,1,l+1); else if(f[x][y]==21&&r==4) chk(x-1,y,4,l+1);
    else if(f[x][y]==22&&r==2) chk(x,y+1,2,l+1); else if(f[x][y]==22&&r==3) chk(x,y-1,3,l+1);
    else if(f[x][y]==31&&r==1) {f[x][y]=22; chk(x+1,y,1,l+1);} else if(f[x][y]==31&&r==4) {f[x][y]=22; chk(x-1,y,4,l+1);}
    else if(f[x][y]==31&&r==2) {f[x][y]=21; chk(x,y+1,2,l+1);} else if(f[x][y]==31&&r==3) {f[x][y]=21; chk(x,y-1,3,l+1);}
}

int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) scanf("%d",&f[i][j]);
    }
    for(i=0;i<n;i++) if(f[i][0]==11||f[i][0]==13||f[i][0]==22||f[i][0]==31) chk(i,0,2,0);
    for(i=0;i<n;i++) if(f[i][m-1]==12||f[i][m-1]==14||f[i][m-1]==22||f[i][m-1]==31) chk(i,m-1,3,0);
    for(i=0;i<m;i++) if(f[0][i]==11||f[0][i]==12||f[0][i]==21||f[0][i]==31) chk(0,i,1,0);
    for(i=0;i<m;i++) if(f[n-1][i]==13||f[n-1][i]==14||f[n-1][i]==21||f[n-1][i]==31) chk(n-1,i,4,0);
    printf("%d\n",ansb);
    for(i=0;i<ansb;i++) printf("%d ",ans[i]);
    return 0;
}
