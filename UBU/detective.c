#include<stdio.h>
#include<string.h>

char dat[10]={};

int chk()
{
    int l,i,t=0;
    while(1)
    {
        l=strlen(dat);
        if(l==1)
        {
            if(dat[0]=='1'||dat[0]=='2'||dat[0]=='3'||dat[0]=='5'||dat[0]=='7') return 0;
            else return 1;
        }
        else
        {
            for(i=0;i<l;i++) t+=dat[i]-48;
            sprintf(dat,"%d",t);
            t=0;
        }
    }
}

int main()
{
    int n,i,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",dat);
        m=chk();
        if(m==0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
