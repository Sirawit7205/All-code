#include<stdio.h>

int cnt[125][30]={},c=1;
char path[30]={};
float ansa=0,ansb=0,tw=2;

int fp(int a,int prev)
{
    int i,x=0;
    for(i=1;i<cnt[a][0];i+=2)
    {
        if(cnt[a][i]==89) {path[c]=a; c++; return 1;}
        else if(cnt[a][i]!=prev) {x=fp(cnt[a][i],a); if(x==1) {path[c]=a; c++; return 1;}}
    }
    return 0;
}

void chk(int a,int b)
{
    int i,j,m[15]={},t,tt,h=0;
    for(i=1;i<cnt[a][0];i+=2)
    {
        if(cnt[a][i]==b)
        {
            t=cnt[a][i+1];
            for(j=0;j<h;j++) if(t<m[j]) {tt=m[j]; m[j]=t; t=tt;}
            m[h]=t; h++;
        }
    }
    if(h%2==0) ansb=(m[h/2]+m[(h/2)-1])/tw; else ansb=m[h/2];
}

int main()
{
    int cn,i,tc,taa,tbb;
    char ta,tb;
    scanf("%d",&cn);
    for(i=0;i<cn;i++)
    {
        scanf(" %c %c %d",&ta,&tb,&tc); taa=ta; tbb=tb;
        cnt[taa][cnt[taa][0]+1]=tbb; cnt[taa][cnt[taa][0]+2]=tc; cnt[taa][0]+=2;
        cnt[tbb][cnt[tbb][0]+1]=taa; cnt[tbb][cnt[tbb][0]+2]=tc; cnt[tbb][0]+=2;
    }
    path[0]='Y'; tc=fp(88,0);
    if(tc==0) {printf("broken"); return 0;}
    for(i=c-1;i>0;i--)
    {
        taa=path[i]; tbb=path[i-1]; chk(tbb,taa);
        printf("%c %c %.1f\n",path[i],path[i-1],ansb);
        ansa+=ansb; ansb=0;
    }
    printf("%.1f",ansa);
    return 0;
}
