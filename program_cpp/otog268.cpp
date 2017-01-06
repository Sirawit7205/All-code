#include<cstdio>

int n,m,f[500][500]={},ln[40005][5]={},lmost=1000,umost=1000,d[40001]={};

void chk(int u,int l,int c,int p)
{
    int i;
    f[u][l]=c;
    if(l<lmost) lmost=l; if(u<umost) umost=u;
    for(i=0;i<4;i++)
    {
        if(ln[c][i]!=0&&d[ln[c][i]]==0&&ln[c][i]!=p)
        {
            d[ln[c][i]]=1;
            if(i==0) chk(u-1,l,ln[c][i],c);
            else if(i==1) chk(u,l-1,ln[c][i],c);
            else if(i==2) chk(u,l+1,ln[c][i],c);
            else chk(u+1,l,ln[c][i],c);
        }
    }
}

int main()
{
    int i,j,ta,tb;
    char mode;
    scanf("%d %d",&n,&m);
    for(i=0;i<(n*m)-1;i++)
    {
        scanf("%d %c %d",&ta,&mode,&tb);
        if(mode=='U')
        {
            ln[tb+1][0]=ta+1;
            ln[ta+1][3]=tb+1;
        }
        else
        {
            ln[ta+1][2]=tb+1;
            ln[tb+1][1]=ta+1;
        }
    }
    d[1]=1;
    chk(250,250,1,0);
    for(i=umost;i<umost+n;i++)
    {
        for(j=lmost;j<lmost+m;j++) printf("%d ",f[i][j]-1); printf("\n");
    }
    return 0;
}
