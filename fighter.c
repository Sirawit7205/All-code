#include<stdio.h>

int main()
{
    int lpo,lpe,amt,t,stro=0,stre=0;
    scanf("%d",&amt);
    lpo=amt; lpe=amt;
    while(1)
    {
        scanf("%d",&t);
        if(t%2==0)
        {
            stro=0;
            stre++;
        }
        else
        {
            stre=0;
            stro++;
        }
        if(t%2==0&&stre>=3)
        {
            lpo-=3;
        }
        else if(t%2==0&&stre<3)
        {
            lpo-=1;
        }
        else if(t%2!=0&&stro>=3)
        {
            lpe-=3;
        }
        else
        {
            lpe-=1;
        }
        if(lpe<=0)
        {
            printf("1\n%d",t);
            break;
        }
        else if(lpo<=0)
        {
            printf("0\n%d",t);
            break;
        }
    }
    return 0;
}
