#include<stdio.h>
#include<limits.h>

int main()
{
    int max=INT_MIN,min=INT_MAX,i,no,t;
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        scanf("%d",&t);
        if(t>max) max=t;
        if(t<min) min=t;
    }
    printf("%d\n%d",min,max);
    return 0;
}
