#include<stdio.h>

int main()
{
    int x,y,z,i,j,t,c[5055][4]={},line[110]={};
    scanf("%d %d %d",&x,&y,&z);
    for(i=1;i<=y;i++)
    {
        scanf("%d %d",&c[i][0],&c[i][1]);
    }
    for(i=1;i<=z;i++)
    {
        scanf("%d",&t);
        c[t][2]++;
    }
    for(i=1;i<=y;i++)
    {
        for(j=c[i][0];j<=c[i][1];j++)
        {
            line[j]+=c[i][2];
        }
    }
    for(i=1;i<=x;i++) printf("%d\n",line[i]);
    return 0;
}
