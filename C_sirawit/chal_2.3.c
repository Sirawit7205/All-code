#include<stdio.h>

int main()
{
    int size,i,j;

    printf("Enter size: ");
    scanf("%d",&size);
    if(size<4||size>100)
    {
        printf("Overflow.");
        return 0;
    }

    for(i=1;i<=size;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}
