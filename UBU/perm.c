#include<stdio.h>

int ord[25]={},na;
long long int con[25]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
long long int ma;

void srt(int a,int b,int m)
{
    int s=0,t,i;
    if(m==1)
    {
        for(i=a;i<b;i++)
        {
            if(ord[i]>ord[i+1])
            {
                s=1;
                t=ord[i];
                ord[i]=ord[i+1];
                ord[i+1]=t;
            }
        }
        if(s==0) return; else {s=0; srt(a,b,m);}
    }
    else
    {
        for(i=a;i<b;i++)
        {
            if(ord[i]<ord[i+1])
            {
                s=1;
                t=ord[i];
                ord[i]=ord[i+1];
                ord[i+1]=t;
            }
        }
        if(s==0) return; else {s=0; srt(a,b,m);}
    }
}

void permgen(long long int m)
{
    int i,sel,t;
    long long int cur,pos;
    if(m==1) return;
    for(i=1;i<=20;i++) if(con[i]>=m) {sel=i; break;}
    cur=m/con[sel-1]; pos=m%con[sel-1];
    if(pos!=0)
    {
        t=ord[(na-sel)+1];
        ord[(na-sel)+1]=ord[(na-sel)+1+cur];
        ord[(na-sel)+1+cur]=t;
        srt((na-sel)+2,na,1);
        permgen(pos);
    }
    else
    {
        t=ord[(na-sel)+1];
        ord[(na-sel)+1]=ord[(na-sel)+cur];
        ord[(na-sel)+cur]=t;
        srt((na-sel)+2,na,2);
        return;
    }
}

int main()
{
    int i;
    scanf("%d %lld",&na,&ma);
    for(i=1;i<=na;i++) ord[i]=i;
    permgen(ma);
    for(i=1;i<=na;i++) printf("%c ",ord[i]+96);
    return 0;
}
