#include<stdio.h>

int dat[1000005][2]={};

int main()
{
    int i,n,m,ta,tb,c=0,r=0,g=0,b=0,ans;
    char a;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&ta,&tb);
        dat[ta][0]++; dat[tb][1]++;
    }
    for(i=1;i<=n;i++)
    {
        c+=dat[i][0];
        if(c%3==0) r++;
        else if(c%3==1) g++;
        else b++;
        c-=dat[i][1];
    }
    scanf(" %c",&a);
    if(a=='R') ans=(g*2)+b;
    else if(a=='G') ans=(b*2)+r;
    else ans=(r*2)+g;
    printf("%d",ans);
    return 0;
}
