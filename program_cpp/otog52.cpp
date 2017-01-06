#include<cstdio>

int dat[105][3]={};

int main()
{
    int q,a,b,c,i,j;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        dat[0][0]=1; dat[0][1]=c;
        for(j=1;j<a;j++)
        {
            dat[j][0]=dat[0][0]-dat[j-1][1];
            dat[j][1]=dat[0][1]-dat[j-1][0];
        }
        if(b>=dat[a-1][0]&&b<=dat[a-1][1]) printf("yes\n"); else printf("no\n");
    }
    return 0;
}
