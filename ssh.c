#include<stdio.h>

int lnklist[65][65]={},m,s,e;

void f(int r,int p,int c)
{
    int i;
    if(r==e) {printf("%d",c); return;}
    for(i=1;i<=lnklist[r][0];i++)
    {
        if(lnklist[r][i]==p) continue;
        else f(lnklist[r][i],r,c+1);
    }
}

int main()
{
    int i,ta,tb;
    scanf("%d %d %d",&m,&s,&e);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&ta,&tb);
        lnklist[ta][lnklist[ta][0]+1]=tb; lnklist[ta][0]++;
        lnklist[tb][lnklist[tb][0]+1]=ta; lnklist[tb][0]++;
    }
    f(s,-1,0);
    return 0;
}
