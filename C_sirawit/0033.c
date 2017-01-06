#include<stdio.h>

int main()
{
    int dat[10002]={},max=0,a,i,temp,c=0,ans[10002]={};
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&temp);
        dat[temp]++;
        if(temp>max) max=temp;
    }
    temp=0;
    for(i=1;i<=max;i++)
    {
        if(dat[i]>temp&&dat[i]!=0) {c=0; ans[c]=i; c++; temp=dat[i];}
        else if(dat[i]==temp&&dat[i]!=0) {ans[c]=i; c++;}
    }
    for(i=0;i<c;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
