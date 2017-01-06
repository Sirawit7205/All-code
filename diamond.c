#include<stdio.h>

int main()
{
    int i,j,n,c;
    scanf("%d",&n);
    if(n==1) {printf("N"); return 0;}
    else
    {
        for(i=0;i<n/2;i++)
        {
            for(j=i;j<n/2;j++) printf(" ");
            printf("*");
            for(j=0;j<i;j++) printf("^*");
            printf("\n");
        }
        if((n/2)%2==0)
        {
            c=0;
            for(i=0;i<n/2;i++)
            {
                if(c==0) {printf("*"); c=1;} else {printf("^"); c=0;}
            }
            printf("N");
            c=1;
            for(i=0;i<n/2;i++)
            {
                if(c==0) {printf("*"); c=1;} else {printf("^"); c=0;}
            }
            printf("\n");
        }
        else
        {
            c=0;
            for(i=0;i<n/2;i++)
            {
                if(c==0) {printf("*"); c=1;} else {printf("^"); c=0;}
            }
            printf("N");
            c=0;
            for(i=0;i<n/2;i++)
            {
                if(c==0) {printf("*"); c=1;} else {printf("^"); c=0;}
            }
            printf("\n");
        }
        for(i=(n/2)-1;i>=0;i--)
        {
            for(j=i;j<n/2;j++) printf(" ");
            printf("*");
            for(j=0;j<i;j++) printf("^*");
            printf("\n");
        }
    }
    return 0;
}
