#include<stdio.h>

int dat[100][100]={}, path[100][100]={}, res[100]={},c=0;

void shrt(int k, int a)
{
    int i,j;
    if(k==a) return;
    for(i=0;i<a;i++)
    {
        if(i==k) continue;
        for(j=0;j<a;j++)
        {
            if(j==k) continue;
            else
            {
                if(dat[k][j]+dat[i][k]<dat[i][j]) {dat[i][j]=dat[k][j]+dat[i][k]; path[i][j]=path[k][j];}
            }
        }
    }
    shrt(k+1,a);
}

void p(int fr, int to)
{
    int i;
    if(path[fr][to]==fr)
    {
        res[c]=fr;
        for(i=c;i>0;i--)
        {
            printf("%d->",res[i]);
        }
        printf("%d",res[0]);
    }
    else {res[c]=path[fr][to]; c++; p(fr,path[fr][to]);}
}

int main()
{
    int i,j,amt,fr,to;
    printf("Node amount: "); scanf("%d",&amt);
    printf("Shortest path from node: "); scanf("%d",&fr);
    printf("Shortest path to node: "); scanf("%d",&to);
    for(i=0;i<amt;i++)
    {
        printf("Enter node %d info (-1 for INF): ",i);
        for(j=0;j<amt;j++)
            {
                scanf("%d",&dat[i][j]);
                if(dat[i][j]<=0) path[i][j]=-1;
                else path[i][j]=i;
                if(dat[i][j]==-1) dat[i][j]=999;
            }
    }
    shrt(0,amt);
    if(dat[fr][to]==999) printf("Traversal not possible.");
    else
    {
    printf("Shortest length= %d\nShortest path= ",dat[fr][to]);
    res[c]=to; c++;
    p(fr,to);
    }
    return 0;
}
