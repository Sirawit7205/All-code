#include<stdio.h>

int w,h,data[100][100]={},dat[100][100]={};

int walk(int row, int col)
{
    int u,r,l,dw;
    if(row==h-1&&col==w-1) return 0;
    if(row<0||col<0||row>=h||col>=w) return -1;
    if(data[row][col]>0) return dat[row][col]=-1;
    if(dat[row][col]>0) return dat[row][col];
    if(dat[row][col]<0) return -1;
    dat[row][col]=-1;
    u=walk(row-1,col);
    r=walk(row,col+1);
    l=walk(row,col-1);
    dw=walk(row+1,col);
    int min=u;
    if(r>=0&&(min<0||min>r)) min=r;
    if(l>=0&&(min<0||min>l)) min=l;
    if(dw>=0&&(min<0||min>dw)) min=dw;
    dat[row][col]=min+1;
    if(min>=0) return dat[row][col];
    return -1;
}

int main ()
{
    int i,j;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++) scanf("%d",&data[i][j]);
    }
    walk(0,0);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++) if(dat[i][j]<0) printf("%d ",dat[i][j]); else printf(" %d ",dat[i][j]);
        printf("\n");
    }
    return 0;
}
