#include<stdio.h>

int prt(char a,int b)
{
    int i,j;
    for(i=1;i<=b;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c",a);
        }
        printf("\n");
    }
}

int main()
{
    char a;
    int b;
    printf("Enter character: "); scanf("%c",&a);
    printf("Number of line: "); scanf("%d",&b);
    prt(a,b);
    return 0;
}
