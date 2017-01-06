#include<stdio.h>

int min,max,ans=0;

int chk(int m,int c)
{
    int i,a=0;
    if(m>max) return ans;
    for(i=2;i<=m-c;i++)
    {
        if(m%i==0) {a=1; break;}
    }
    if(a==0||m==2) {ans+=m;}
    chk(m+1,2);
}

int main()
{
    scanf("%d",&min);
    scanf("%d",&max);
    ans=chk(min,2);
    printf("%d",ans);
    return 0;
}
