#include<cstdio>

int n,m,qa[505][505]={},qb[505][505]={};

int main()
{
    int i,j,k,n,m,t,ta,tb,s;
    scanf("%d %d %d",&n,&m,&t);
    for(i=0;i<t;i++) {scanf("%d %d",&ta,&tb); qa[ta+1][tb+1]=1;}
    if(n<=m) s=n; else s=m;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) qa[i][j]+=qa[i-1][j]+qa[i][j-1]-qa[i-1][j-1];
    for(k=s;k>=1;k--)
    {
        for(i=k;i<=n;i++)
        {
            for(j=k;j<=m;j++)
                if((qa[i][j]-qa[i-k][j]-qa[i][j-k]+qa[i-k][j-k])-(qa[i-1][j-1]-qa[i+1-k][j-1]-qa[i-1][j+1-k]+qa[i+1-k][j+1-k])==0) {printf("%d\n",k); s=-1; break;}
            if(s==-1) break;
        }
        if(s==-1) break;
    }
    scanf("%d %d %d",&n,&m,&t);
    for(i=0;i<t;i++) {scanf("%d %d",&ta,&tb); qb[ta+1][tb+1]=1;}
    if(n<=m) s=n; else s=m;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) qb[i][j]+=qb[i-1][j]+qb[i][j-1]-qb[i-1][j-1];
    for(k=s;k>=1;k--)
    {
        for(i=k;i<=n;i++)
        {
            for(j=k;j<=m;j++)
                if((qb[i][j]-qb[i-k][j]-qb[i][j-k]+qb[i-k][j-k])-(qb[i-1][j-1]-qb[i+1-k][j-1]-qb[i-1][j+1-k]+qb[i+1-k][j+1-k])==0) {printf("%d\n",k); s=-1; break;}
            if(s==-1) break;
        }
        if(s==-1) break;
    }
    return 0;
}
