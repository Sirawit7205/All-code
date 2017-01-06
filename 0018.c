#include<stdio.h>

int main()
{
    int i,j,n,k,c=1,dat[1002]={};
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++)
    {
        if(dat[i]==1) continue;
        for(j=2;j<=n;j++)
        {
            if(j%i==0&&dat[j]==0&&c==k) {printf("%d",j); return 0;}
            else if(j%i==0&&dat[j]==0) {c++; dat[j]=1;}
        }
    }
    return 0;
}
