#include<stdio.h>

int main()
{
    int i,q,n,m;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",(n*m*(n+1)*(m+1))/4);
    }
    return 0;
}
