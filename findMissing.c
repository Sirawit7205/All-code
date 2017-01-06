#include<stdio.h>

int main()
{
    int i,size,data[100]={},tmp,min=999,max,c=0;
    scanf("%d",&size);
    while(tmp!=-1)
    {
        scanf("%d",&tmp);
        if(tmp==-1) break;
        data[tmp]=1;
        if(tmp<min) min=tmp; max=min+size;
    }
    for(i=min;i<max;i++)
    {
        if(data[i]==0)
        {printf("%d ",i); c=1;}
    }
    if(c==0)
    {printf("No missing");}
    return 0;
}
