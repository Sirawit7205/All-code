#include<stdio.h>

int main()
{
    int i,q;
    float a,m,n;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%f:%f",&m,&n);
        if(m>12) m-=12;
        a=(0.5*((60*m)-(11*n)));
        if(a<0) a*=-1;
        if(a>180) printf("%.2f\n",360-a);
        else printf("%.2f\n",a);
    }
    return 0;
}
