#include<stdio.h>

int main()
{
    int i,n,ca,cb=0;
    scanf("%d",&n);
    if(n%2==0) printf("error");
    else
    {
        ca=n;
        while(ca>=1)
        {
            for(i=0;i<cb;i++) printf(" ");
            for(i=0;i<ca;i++) printf("*");
            for(i=0;i<cb;i++) printf(" ");
            printf("\n");
            ca-=2; cb++;
        }
        ca=3; cb-=2;
        while(ca<=n)
        {
            for(i=0;i<cb;i++) printf(" ");
            for(i=0;i<ca;i++) printf("*");
            for(i=0;i<cb;i++) printf(" ");
            printf("\n");
            ca+=2; cb--;
        }
    }
    return 0;
}
