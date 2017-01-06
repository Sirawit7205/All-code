#include<stdio.h>

int main()
{
    int n[11][11]={},a,i,j,sum=0,chk=0;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            scanf("%d",&n[i][j]);
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            sum+=n[i][j];
        }
        if(chk==0) chk=sum;
        else
        {
            if(sum!=chk) {printf("No"); return 0;}
        }
        sum=0;
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            sum+=n[j][i];
        }
        if(sum!=chk) {printf("No"); return 0;}
        sum=0;
    }
    for(i=0;i<a;i++)
    {
        sum+=n[i][i];
    }
    if(sum!=chk) {printf("No"); return 0;}
    sum=0;
    for(i=0;i<a;i++)
    {
        for(j=a;j>=0;j--)
        {
            sum+=n[i][j];
        }
        if(sum!=chk) {printf("No"); return 0;}
        sum=0;
    }
    printf("Yes");
    return 0;
}
