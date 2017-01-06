#include<stdio.h>

int main()
{
    int i,n,t,min=2000000001,max=-2000000001;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t<min) min=t;
        if(t>max) max=t;
    }
    printf("%d\n%d",max,min);
    return 0;
}
