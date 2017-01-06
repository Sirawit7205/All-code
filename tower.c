#include<stdio.h>

int kp[50005]={};

int main()
{
    int lev,amt=1,i,j,err,h;
    scanf("%d %d",&lev,&h);
    kp[1]=2;
    if(lev==1) printf("0");
    else
    {
        for(i=3;i<=lev;i+=2)
        {
            err=0;
            for(j=1;j<=amt;j++)
            {
                if(i%kp[j]==0) {err=1; break;}
            }
            if(err==0) {amt++; kp[amt]=i;}
        }
        if(h>=amt) printf("0");
        else printf("%d",amt-h);
    }
    return 0;
}
