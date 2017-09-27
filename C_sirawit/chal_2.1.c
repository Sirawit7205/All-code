#include<stdio.h>

int main()
{
    int size,i,j;

    printf("Enter size: ");
    scanf("%d",&size);
    if(size<3||size>100)
    {
        printf("Overflow.");
        return 0;
    }

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
