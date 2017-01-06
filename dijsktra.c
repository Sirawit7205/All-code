#include<stdio.h>

#define INF 999

int dat[100][100]={};

int main()
{
    int i,j,amt,fr,to;
    printf("Node amount: "); scanf("%d",&amt);
    printf("Shortest path from: "); scanf("%d",&fr);
    printf("Shortest path to: "); scanf("%d",&to);
    for(i=0;i<amt;i++)
    {
        printf("Enter node %d info: ",i);
        for(j=0;j<amt;j++) scanf("%d",&dat[i][j]);
    }

    return 0;
}
