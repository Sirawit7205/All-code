#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[305][305]={},m,n,ep[100000]={},ec=0,l=0;

void chk(int x,int y,int z)
{
    int t;
    if(x==0||y==0||x==m+1||y==n+1) {ep[ec]=l; ec++; l=0; return;}
    t=a[x][y]; l++;
    if(t==11) {if(z==4) chk(x,y-1,2); else chk(x-1,y,1);}
    else if(t==12) {if(z==4) chk(x,y+1,3); else chk(x-1,y,1);}
    else if(t==13) {if(z==1) chk(x,y-1,2); else chk(x+1,y,4);}
    else if(t==14) {if(z==1) chk(x,y+1,3); else chk(x+1,y,4);}
    else if(t==21) {if(z==1) chk(x-1,y,1); else chk(x+1,y,4);}
    else if(t==22) {if(z==2) chk(x,y-1,2); else chk(x,y+1,3);}
    else if(t==31) {if(z==1) chk(x-1,y,1); else if(z==2) chk(x,y-1,2); else if(z==3) chk(x,y+1,3); else chk(x+1,y,4);}
}

int main()
{
    int i,j,t;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&t); a[i][j]=t;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[1][i]==21) chk(1,i,4);
        else if(a[1][i]==11) {if(i==1) {chk(1,i,4); chk(1,i,3);} else chk(1,i,4);}
        else if(a[1][i]==12) {if(i==n) {chk(1,i,4); chk(1,i,2);} else chk(1,i,4);}
        else if(a[1][i]==13&&i==1) chk(1,1,3);
        else if(a[1][i]==14&&i==n) chk(1,n,2);
        else if(a[1][i]==22) {if(i==1) chk(1,i,3); else if(i==n) chk(1,i,2);}
        else if(a[1][i]==31) {if(i==1) {chk(1,i,3); chk(1,i,4);} else if(i==n) {chk(1,i,2); chk(1,i,4);} else chk(1,i,4);}
    }
    if(m!=1)
    {
        for(i=1;i<=n;i++)
        {
        if(a[m][i]==21) chk(m,i,1);
        else if(a[m][i]==13) {if(i==1) {chk(m,i,1); chk(m,i,3);} else chk(m,i,1);}
        else if(a[m][i]==14) {if(i==n) {chk(m,i,1); chk(m,i,2);} else chk(m,i,1);}
        else if(a[m][i]==11&&i==1) chk(m,1,3);
        else if(a[m][i]==12&&i==n) chk(m,n,2);
        else if(a[m][i]==22) {if(i==1) chk(m,i,3); else if(i==n) chk(m,i,2);}
        else if(a[m][i]==31) {if(i==1) {chk(m,i,1); chk(m,i,3);} else if(i==n) {chk(m,i,1); chk(m,i,2);} else chk(m,i,1);}
        }
    }
    for(i=2;i<m;i++)
    {
        if(a[i][1]==11||a[i][1]==13||a[i][1]==22||a[i][1]==31) chk(i,1,3);
    }
    if(n!=1)
    {
        for(i=2;i<m;i++)
        {
            if(a[i][n]==12||a[i][n]==14||a[i][n]==22||a[i][n]==31) chk(i,n,2);
        }
    }
    sort(ep,ep+ec);
    if((m==1||n==1)&&ec!=2)
    {
        printf("%d\n",ec);
        for(i=0;i<ec;i++)
        {
            printf("%d ",ep[i]);
        }
    }
    else
    {
        printf("%d\n",ec/2);
        for(i=0;i<ec;i+=2)
        {
            printf("%d ",ep[i]);
        }
    }
    return 0;
}
