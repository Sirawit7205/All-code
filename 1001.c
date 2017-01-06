#include<stdio.h>

char dat[25][25]={},te;

int main()
{
    int n,m,i,j,t,c=0,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=m;j++)
        {
            scanf("%c",&te); if(te!='\n') dat[i][j-1]=te;
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&t);
        for(k=0;k<t;k++)
        {
            c=0;
            if(dat[0][i]=='#'||dat[0][i]=='O') break;
            for(j=0;j<n;j++)
            {
                if(dat[j][i]=='#'||dat[j][i]=='O') {dat[j-1][i]='#'; c=1; break;}
            }
            if(c==0) dat[j-1][i]='#';
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) printf("%c",dat[i][j]);
        printf("\n");
    }
    return 0;
}
