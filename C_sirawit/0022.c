#include<stdio.h>

int main()
{
    int a,i,j;
    scanf("%d",&a);
    if(a==1) printf("*");
    else if(a%2==0){
    for(i=0;i<a/2;i++)
    {
        for(j=a/2;j>i+1;j--) printf("-");
        if(i!=0) printf("*");
        for(j=0;j<i*2-1;j++) printf("-");
        printf("*");
        for(j=a/2;j>i+1;j--) printf("-");
        printf("\n");
    }
    for(i=a/2-1;i>=0;i--)
    {
        for(j=a/2;j>i+1;j--) printf("-");
        if(i!=0) printf("*");
        for(j=0;j<i*2-1;j++) printf("-");
        printf("*");
        for(j=a/2;j>i+1;j--) printf("-");
        printf("\n");
    }
    }
    else
    {
        for(i=0;i<a/2;i++)
    {
        for(j=a/2;j>i;j--) printf("-");
        if(i!=0) printf("*");
        for(j=0;j<i*2-1;j++) printf("-");
        printf("*");
        for(j=a/2;j>i;j--) printf("-");
        printf("\n");
    }
    for(i=a/2;i>=0;i--)
    {
        for(j=a/2;j>i;j--) printf("-");
        if(i!=0) printf("*");
        for(j=0;j<i*2-1;j++) printf("-");
        printf("*");
        for(j=a/2;j>i;j--) printf("-");
        printf("\n");
    }
    }
    return 0;
}
