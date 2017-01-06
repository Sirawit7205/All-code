#include<stdio.h>

int dat[10005][5]={};

int main()
{
    int n,m,k,q,i,j,ta,tb,tc,a=0;
    scanf("%d %d %d %d",&n,&m,&k,&q);
    for(i=0;i<k;i++)
    {
        scanf("%d %d %d",&ta,&tb,&tc);
        dat[i][0]=ta-(tc/2); dat[i][1]=tb-(tc/2); dat[i][2]=ta+(tc/2); dat[i][3]=tb+(tc/2);
    }
    for(i=0;i<q;i++)
    {
        a=0;
        scanf("%d %d",&ta,&tb);
        for(j=0;j<k;j++)
        {
            if(ta>=dat[j][0]&&ta<=dat[j][2]&&tb>=dat[j][1]&&tb<=dat[j][3]) a++;
        }
        printf("%d\n",a);
    }
    return 0;
}
