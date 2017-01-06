#include<stdio.h>

double land[5][5]={},cpy[5][5]={},sum=0,ans=999999999999;
int des[10][3]={},use[10]={},res[10]={},xx,yy;

void summ()
{
    int i, x, y;
    for(i=1;i<=xx*yy;i++)
    {
        x=des[res[i]][0]; y=des[res[i]][1];
        double ad=cpy[x][y]*0.1;
        sum+=cpy[x][y];
        cpy[x-1][y-1]+=ad; cpy[x-1][y]+=ad; cpy[x-1][y+1]+=ad; cpy[x][y-1]+=ad; cpy[x][y+1]+=ad; cpy[x+1][y-1]+=ad; cpy[x+1][y]+=ad; cpy[x+1][y+1]+=ad;
    }
}

void perm(int r,int a)
{
    int i,j;
    if(r>a) {summ(); if(sum<ans) ans=sum; sum=0; for(i=1;i<=xx;i++) for(j=1;j<=yy;j++) cpy[i][j]=land[i][j]; return;}
    for(i=1;i<=a;i++) {if(use[i]==0) {use[i]=1; res[r]=i; perm(r+1,a); use[i]=0;}}
}

int main()
{
    int i,j,p=1;
    scanf("%d %d",&xx,&yy);
    for(i=1;i<=xx;i++) for(j=1;j<=yy;j++) {scanf("%lf",&land[i][j]); des[p][0]=i; des[p][1]=j; p++;}
    for(i=1;i<=xx;i++) for(j=1;j<=yy;j++) cpy[i][j]=land[i][j];
    perm(1,xx*yy);
    printf("%.2f",ans);
    return 0;
}
