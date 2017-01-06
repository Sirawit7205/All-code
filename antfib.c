#include<stdio.h>

int cache[1001]={},a,b;

int antfib(int n)
{
    int t;
    if(n==0) return a;
    if(n==1) return b;
    if((n/2)%2==1)
    {
        if(cache[n-1]!=0&&cache[n-2]!=0) t=cache[n-1]+cache[n-2];
        else if(cache[n-1]!=0&&cache[n-2]==0) t=cache[n-1]+antfib(n-2);
        else if(cache[n-1]==0&&cache[n-2]!=0) t=antfib(n-1)+cache[n-2];
        else t=antfib(n-1)+antfib(n-2);
        if(cache[n]==0) cache[n]=t;
        return t;
    }
   else
   {
       if(cache[n-1]!=0&&cache[n-4]!=0) t=cache[n-1]-cache[n-4];
       else if(cache[n-1]!=0&&cache[n-4]==0) t=cache[n-1]-antfib(n-4);
       else if(cache[n-1]==0&&cache[n-4]!=0) t=antfib(n-1)-cache[n-4];
       else t=antfib(n-1)-antfib(n-4);
       if(cache[n]==0) cache[n]=t;
       return t;
   }
}

int main()
{
    int i,q,n;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d %d",&a,&b,&n);
        cache[0]=a; cache[1]=b;
        printf("%d\n",antfib(n));
    }
    return 0;
}
