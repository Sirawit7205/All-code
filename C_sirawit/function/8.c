#include<stdio.h>

int prt(char w[1000],int r)
{
    int i;
    for(i=0;i<r;i++) puts(w);
    return 0;
}

int main()
{
    char w[1000]={};
    int r;
    printf("Enter message: "); gets(w);
    printf("Enter number: "); scanf("%d",&r);
    prt(w,r);
    return 0;
}
