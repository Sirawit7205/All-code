#include<cstdio>

int pos[5]={},r,c;
char m[15][15]={};

int main()
{
    int i,j,scr;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++) scanf(" %c",&m[i][j]);
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(m[i][j]=='X')
            {
                scr=0;
                if(m[i-1][j]=='.') scr++;
                if(m[i+1][j]=='.') scr++;
                if(m[i][j-1]=='.') scr++;
                if(m[i][j+1]=='.') scr++;
                if(scr>=3) m[i][j]='O';
                else
                {
                    if(pos[0]==0) {pos[0]=i; pos[1]=i;}
                    if(pos[2]==0) {pos[2]=j; pos[3]=j;}
                    if(i>pos[1]) pos[1]=i;
                    if(j>pos[3]) pos[3]=j;
                    if(i<pos[0]) pos[0]=i;
                    if(j<pos[2]) pos[2]=j;
                }
            }
        }
    }
    for(i=pos[0];i<=pos[1];i++)
    {
        for(j=pos[2];j<=pos[3];j++) {if(m[i][j]=='O') printf("."); else printf("%c",m[i][j]);} printf("\n");
    }
    return 0;
}
