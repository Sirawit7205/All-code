#include<stdio.h>

int n;

int findbelow(int x)
{
    int i,f=0;
    if(x==2) return x;
    if(x%2==0) findbelow(x-1);
    else
    {
        for(i=3;i<=x/2;i+=2) if(x%i==0) {f=1; break;}
        if(f==0) return x; else findbelow(x-1);
    }
}

int findabove(int x)
{
    int i,f=0;
    if(x==2) return x;
    if(x%2==0) findabove(x+1);
    else
    {
        for(i=3;i<=x/2;i+=2) if(x%i==0) {f=1; break;}
        if(f==0) return x; else findabove(x+1);
    }
}

int main()
{
    scanf("%d",&n);
    //if(n<0) n=n*-1;
    if(n<=0||n==1) {printf("Mr.Nonz 2"); return 0;}
    else if(n==2) {printf("Mr.Nonz 3"); return 0;}
    else printf("%d %d",findbelow(n-1),findabove(n+1));
    return 0;
}

