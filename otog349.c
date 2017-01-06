#include<stdio.h>

int s[5][100005]={},d[100005]={},n,m;
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(j=1;j<=m;j++) scanf("%d",&d[i]);
    }
}
