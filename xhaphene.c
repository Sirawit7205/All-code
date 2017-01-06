#include<stdio.h>

int lnklist[10005][3]={};

int main()
{
    int i,n,h,ta,tb,c=1,prev;
    scanf("%d",&n);
    h=(n/2)+1;
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d",&ta,&tb);
        lnklist[ta][lnklist[ta][0]+1]=tb; lnklist[ta][0]++;
        lnklist[tb][lnklist[tb][0]+1]=ta; lnklist[tb][0]++;
    }
    for(i=1;i<=n;i++) if(lnklist[i][0]==1) break;
    while(1)
    {
        if(c==h) {printf("%d",i); break;}
        if(lnklist[i][0]==1) {prev=i; i=lnklist[i][1];}
        else if(lnklist[i][1]==prev) {prev=i; i=lnklist[i][2];}
        else {prev=i; i=lnklist[i][1];}
        c++;
    }
    return 0;
}
