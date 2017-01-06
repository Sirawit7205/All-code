#include<iostream>
#include<cstdio>

using namespace std;

int a[1001][1001]={},ma=0,cc=0,n,m;

void chk(int ac,int b,int c,int d)
{
    if(ac==m) {if(c>ma) {ma=c; cc=1;} else if(c==ma) cc++; return;}
    c+=a[ac][b];
    if((ac%2==0&&d==0&&b==0)||(ac%2==1&&d==1&&b==n-1)) {if(c>ma) {ma=c; cc=1;} else if(c==ma) cc++; return;}
    if(ac%2==0) {chk(ac+1,b,c,0); chk(ac+1,b+1,c,1);}
    else {chk(ac+1,b-1,c,0); chk(ac+1,b,c,1);}
}

int main()
{
    int i,j;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        chk(0,i,0,0);
        chk(0,i,0,1);
    }
    printf("%d %d",ma,cc);
    return 0;
}
