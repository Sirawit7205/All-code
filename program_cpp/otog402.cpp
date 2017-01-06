#include<cstdio>

int str[20][20][2]={},dat[20][20]={},n,m;

int recur(int r,int col)
{
    int ta,tb,tc;
    if(col==m) return str[r][col][0]=dat[r][col];
    if(r>1) {if(str[r-1][col+1][0]==0) ta=recur(r-1,col+1); else ta=str[r-1][col+1][0];} else ta=99999999;
    if(str[r][col+1][0]==0) tb=recur(r,col+1); else tb=str[r][col+1][0];
    if(r<n) {if(str[r+1][col+1][0]==0) tc=recur(r+1,col+1); else tc=str[r+1][col+1][0];} else tc=99999999;
    if(ta<=tb&&ta<=tc) {str[r][col][0]=ta+dat[r][col]; str[r][col][1]=1; return ta+dat[r][col];}
    else if(tb<=ta&&tb<=tc) {str[r][col][0]=tb+dat[r][col]; str[r][col][1]=2; return tb+dat[r][col];}
    else if(tc<=ta&&tc<=tb) {str[r][col][0]=tc+dat[r][col]; str[r][col][1]=3; return tc+dat[r][col];}
}

void trback(int r,int col)
{
    printf("%d ",dat[r][col]);
    if(col==m) return;
    if(str[r][col][1]==1) trback(r-1,col+1);
    else if(str[r][col][1]==2) trback(r,col+1);
    else trback(r+1,col+1);
}

int main()
{
    int i,j,r;
    scanf("%d %d",&n,&m);
    scanf("%d",&r);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) scanf("%d",&dat[i][j]);
    }
    printf("%d\n",recur(r,1));
    trback(r,1);
    return 0;
}
