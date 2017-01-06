#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int p[15][4]={},a[15][4]={},s[11]={},u[11]={},m,mi=10000000,x,y,z,n;

void fmin()
{
    int i,sum=0,fx=x,fy=y,fz=z,tm=0,tk=0,tc=0;
    for(i=1;i<=m;i++)
    {
        sum+=(p[s[i]][0]-fx)*(p[s[i]][0]-fx)+(p[s[i]][1]-fy)*(p[s[i]][1]-fy)+(p[s[i]][2]-fz)*(p[s[i]][2]-fz);
        tm+=a[s[i]][0]; tk+=a[s[i]][1]; tc+=a[s[i]][2];
        fx=p[s[i]][0]; fy=p[s[i]][1]; fz=p[s[i]][2];
        if(tm>=n&&tk>=n&&tc>=n) {if(sum<mi) {mi=sum;} break;}
    }
    memset(s,0,sizeof(int[0]));
}

void c(int na)
{
    int i;
    if(na>m) {fmin(); return;}
    else
        for(i=1;i<=m;i++)
    {
        if(u[i]==0)
        {
            u[i]=1;
            s[na]=i;
            c(na+1);
            u[i]=0;
        }
    }
}

int main()
{
    int i;
    scanf("%d %d %d %d %d",&n,&x,&y,&z,&m);
    for(i=1;i<=m;i++) scanf("%d %d %d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&a[i][0],&a[i][1],&a[i][2]);
    c(1);
    printf("%d",mi);
    return 0;
}
