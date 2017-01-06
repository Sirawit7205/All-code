#include<stdio.h>

int c[102][102]={},amt[102]={},color[102]={},n;

/*void recur(int a, int cn)
{
    int i;
    if(a>n) return;
    if(amt[a]==0) recur(a+1,cn);
    for(i=0;i<amt[i];i++)
    {

    }
}*/

int main()
{
    int i,j=0,t,cn=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        while(1)
        {
            scanf("%d",&t);
            if(t==0) {amt[i]=j; break;}
            else c[i][j]=t;
            j++;
        }
        j=0;
    }
    //recur(1,1);
    for(i=1;i<n;i++)
    {
        if(amt[i]==0) continue;
        if(color[i]==cn) {printf("no"); return 0;} else {color[i]=cn;}
        for(j=0;j<amt[i];j++)
        {
            if(color[c[i][j]]==cn) {printf("no"); return 0;}
            else if(cn==1) color[c[i][j]]=-1; else color[c[i][j]]=1;
        }
        if(cn==1) cn=-1; else cn=1;
    }
    printf("yes");
    return 0;
}
