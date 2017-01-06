#include<stdio.h>
//#include<time.h>
int amt,spd,dat[30001];

int main()
{
    int i,j,tmp,max=0,sum=0;
    scanf("%d %d",&amt,&spd);
    for(i=0;i<amt;i++) scanf("%d",&dat[i]);
    //printf("%d",clock());
    for(i=0;i<amt;i++)
    {
        tmp=dat[i]+spd; j=i;
        if(tmp>dat[amt-1]) break;
        while(j<tmp)
        {
            if(dat[j]<=tmp&&dat[j]>=i&&dat[j+1]<=tmp&&dat[j+1]>=i)
            {sum+=2; j+=2;}
            else if(dat[j]<=tmp&&dat[j]>=i)
            {sum++; j++;}
            else break;
        }
        if(sum>max) max=sum;
        sum=0; j=0;
    }
    printf("%d\n",max-1);
    //printf("%d",clock());
    return 0;
}
