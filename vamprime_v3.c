#include<stdio.h>

int main()
{
    int n,i,j,x,t=0;
    scanf("%d",&n);
    if(n<=1) printf("Mr.Nonz 2");
    else if(n==2) printf("Mr.Nonz 3");
    else
    {
        x=n-1;
        while(1)
        {
            t=0;
            if(x%2==0) x--;
            else
            {
                for(i=3;i<=x/2;i+=2) if(x%i==0) {x--; t=1; break;}
                if(t==0) {printf("%d ",x); break;}
            }
        }
        x=n+1;
        while(1)
        {
            t=0;
            if(x%2==0) x++;
            else
            {
                for(i=3;i<=x/2;i+=2) if(x%i==0) {x++; t=1; break;}
                if(t==0) {printf("%d ",x); break;}
            }
        }
    }
    return 0;
}
