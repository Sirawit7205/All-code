#include<stdio.h>

int main()
{
    float num[11],last;
    int i,j=0,k;
    for(i = 1; i <=10; i++)
    {
        printf("Enter number #%d : ",i);
        scanf("%f",&num[i]);
    }
    for(i=1; i<=10; i++)
    {
        j=0;
        for(k=1; k<=10; k++)
        {
            if(num[k] > num[k+1])
            {
                j=1;
                last=num[k+1];
                num[k+1] = num[k];
                num[k]=last;
            }
        }
        if(j == 0)break;

    }
    for(i=1; i<=10; i++)
    {
        printf("%.4f\n",num[i]);
    }
}

