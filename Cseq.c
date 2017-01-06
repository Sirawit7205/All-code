#include<stdio.h>

int dat[200005][3]={};
double total=0,ans;

int main()
{
    int i,n,mode,val,op,pt=1,tare=0,tt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&mode);
        {
            if(mode==1) {scanf("%d %d",&op,&val); total+=op*val; dat[tare][1]=op; dat[tare][2]=val; tare++;}
            else if(mode==2) {scanf("%d",&val); dat[pt][0]=val; pt++; total+=val;}
            else
                {
                    for(mode=0;mode<tare;mode++)
                    {
                        if(pt<=dat[mode][1]) tt+=dat[mode][2];
                    }
                    total-=dat[pt-1][0]+tt; pt--; tt=0;
                }
        }
        ans=total/pt;
        printf("%lf\n",ans);
    }
    return 0;
}
