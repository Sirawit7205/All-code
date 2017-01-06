#include<stdio.h>

int an[40]={},a;

void prt(int t)
{
    int i,j,m=0;
    for(i=1;i<=t;i++) {if(an[i]>m) m=an[i];}
    for(i=m;i>0;i--)
    {
        for(j=1;j<=t;j++) if(an[j]>=i) printf("#"); else printf(".");
        printf("\n");
    }
    printf("=\n");
}

void rec(int p,int c,int l,int r)
{
    int i,j;
    for(i=1;i<=(a/2)+1;i++)
    {
        if(r==l&&c>p) {an[r]=c; prt(r); return;}
        else if(i>p) {an[r]=i; rec(i,c-i,l,r+1);}
    }
}

int main()
{
    int i;
    scanf("%d",&a); an[1]=a;
    for(i=1;i<=(a/2)+1;i++) rec(0,a,i,1);
    return 0;
}
