#include<stdio.h>

int main()
{
    int i,a,b,c,jump,sum=0,ans[13]={};
    for(i=0;i<12;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        jump=0; sum=0;
        while(jump<=c)
        {
            jump+=a;
            if(jump<=c)
            {
                jump-=b;
            }
            sum++;
        }
        ans[i]=sum;
    }
    for(i=0;i<12;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
