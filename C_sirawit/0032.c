#include<stdio.h>

int main()
{
    int i,j,a,dat[11]={},temp,min=9,max=0;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&temp);
        dat[temp]++;
        if(temp>max&&temp!=0) max=temp;
        if(temp<min&&temp!=0) min=temp;
    }
    if(dat[0]!=0)
    {
        printf("%d",min);
        for(i=0;i<dat[0];i++) printf("0");
        for(i=0;i<dat[min]-1;i++) printf("%d",min);
        for(i=min+1;i<=max;i++)
        {
            for(j=0;j<dat[i];j++)
            {
                printf("%d",i);
            }
        }
    }
    else
    {
        for(i=min;i<=max;i++)
        {
            for(j=0;j<dat[i];j++)
            {
                printf("%d",i);
            }
        }
    }
    return 0;
}
