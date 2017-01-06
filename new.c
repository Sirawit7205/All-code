#include<stdio.h>

int main()
{
    int no[11][1005]={},amt,i,j,sum=0;
    scanf("%d",&amt);
    for(i=0;i<amt;i++)
    {
        scanf("%d",&no[i][0]);
        for(j=(no[i][0]/2)+1;j<=no[i][0];j++)
        {scanf("%d",&no[i][j]);}
    }
    for(i=0;i<amt;i++)
    {
        sum=0;
        for(j=no[i][0]-1;j>0;j-=2)
        {
            if(no[i][j]<no[i][j+1]) {no[i][j/2]+=no[i][j]; no[i][j+1]-=no[i][j]; no[i][j]=0; sum+=no[i][j+1];}
            else {no[i][j/2]+=no[i][j+1]; no[i][j]-=no[i][j+1]; no[i][j+1]=0; sum+=no[i][j];}
        }
        printf("%d\n",sum+no[i][1]);
    }
}
