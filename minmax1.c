#include<stdio.h>
#include<limits.h>

int main()
{
    int i,len,dat[100]={},min,max;
    scanf("%d",&len);
    for(i=0;i<len;i++) scanf("%d",&dat[i]);
    min=INT_MAX; max=0;
    for(i=0;i<len;i++)
    {
        if(dat[i]<min) min=dat[i];
        if(max<dat[i]) max=dat[i];
    }
    printf("%d\n%d",max,min);
    return 0;
}
