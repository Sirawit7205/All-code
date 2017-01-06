#include<stdio.h>
#include<limits.h>

int main()
{
    int x,y,i,j,max=INT_MIN,cnt=0,a1,b1,ans=0;
    int a[101][101]={},b[101][101]={};
    scanf("%d %d",&x,&y);
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++) {scanf("%d",&a[i][j]); ans+=a[i][j];}
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++) scanf("%d",&b[i][j]);
    }
    for(i=0;i<x;i++)
    {
        if(i-1>=0) for(j=0;j<y;j++) cnt+=b[i-1][j];
        if(i+1<=x) for(j=0;j<y;j++) cnt+=b[i+1][j];
        for(j=0;j<y;j++) cnt-=a[i][j];
        if(cnt>max) {max=cnt; a1=0; b1=i;}
        cnt=0;
    }
    for(i=0;i<y;i++)
    {
        if(i-1>=0) for(j=0;j<x;j++) cnt+=b[j][i-1];
        if(i+1<=y) for(j=0;j<x;j++) cnt+=b[j][i+1];
        for(j=0;j<x;j++) cnt-=a[j][i];
        if(cnt>max) {max=cnt; a1=1; b1=i;}
        cnt=0;
    }
    //printf("%d",max);
    if(a1==0)
    {
        for(i=0;i<y;i++) ans-=a[b1][i];
        if(b1-1>=0) for(j=0;j<y;j++) ans+=b[b1-1][j];
        if(b1+1<=x) for(j=0;j<y;j++) ans+=b[b1+1][j];
    }
    else
    {
        for(i=0;i<x;i++) ans-=a[i][b1];
        if(b1-1>=0) for(j=0;j<x;j++) ans+=b[j][b1-1];
        if(b1+1<=y) for(j=0;j<x;j++) ans+=b[j][b1+1];
    }
    printf("%d",ans);
    return 0;
}
