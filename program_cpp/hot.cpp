#include<iostream>
#include<cstdio>
//#include<queue>

using namespace std;

struct a
{
   int x,y;
   //a(int xx,int yy) {x=xx; y=yy;}
};

struct a q[1000005];
//queue<a> q;
int f[1005][1005]={},chk[1005][1005]={};

int main()
{
    int n,i,j,mi=1000000,mx=0,sa,sb,tx,ty,mid,ta,tb,h,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)
    {
        scanf("%d",&f[i][j]);
        if(f[i][j]==0) {sa=i; sb=j;}
        else {if(f[i][j]<mi) mi=f[i][j]; if(f[i][j]>mx) mx=f[i][j];}
    }
    tx=mi; ty=mx; mid=(tx+ty)/2; mx=1000000;
    while(tx<=ty)
    {
        /*q.push(a(sa,sb));*/ mi=0; h=0; t=1; q[0].x=sa; q[0].y=sb;
        while(h<t)
        {
            ta=q[h].x; tb=q[h].y; h++; chk[ta][tb]=1;
            if(f[ta][tb]==0&&ta!=sa&&tb!=sb) {mi=1; break;}
            if(chk[ta-1][tb]==0&&f[ta-1][tb]<=mid&&ta-1>0) {chk[ta-1][tb]=1; q[t].x=ta-1; q[t].y=tb; t++;}
            if(chk[ta+1][tb]==0&&f[ta+1][tb]<=mid&&ta+1<=n) {chk[ta+1][tb]=1; q[t].x=ta+1; q[t].y=tb; t++;}
            if(chk[ta][tb-1]==0&&f[ta][tb-1]<=mid&&tb-1>0) {chk[ta][tb-1]=1; q[t].x=ta; q[t].y=tb-1; t++;}
            if(chk[ta][tb+1]==0&&f[ta][tb+1]<=mid&&tb+1<=n) {chk[ta][tb+1]=1; q[t].x=ta; q[t].y=tb+1; t++;}
        }
        if(mi==0) tx=mid+1; else if(mi==1) {ty=mid-1; if(mid<mx) mx=mid;}
        mid=(tx+ty)/2;
        for(i=1;i<=n;i++) for(j=1;j<=n;j++) chk[i][j]=0;
    }
    printf("%d",mx);
    return 0;
}
